#include <bits/stdc++.h>

const std::vector<int> directionX{-1, 1, 0, 0};
const std::vector<int> directionY{0, 0, -1, 1};

int main() {
	freopen("multimoo.in", "r", stdin);
	freopen("multimoo.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int sizeGrid;
	std::cin >> sizeGrid;
	std::vector<std::vector<int>> grid(sizeGrid, std::vector<int>(sizeGrid));
	for (int row = 0; row < sizeGrid; row++) {
		for (int column = 0; column < sizeGrid; column++) {
			std::cin >> grid[row][column];
		}
	}
	std::vector<std::vector<bool>> visited(sizeGrid, std::vector<bool>(sizeGrid, false));
	std::vector<std::vector<int>> region(sizeGrid, std::vector<int>(sizeGrid));
	std::vector<std::vector<std::pair<int, int>>> cellRegion;
	int bestOneRegion = 0;
	std::queue<std::pair<int, int>> queue;
	for (int row = 0; row < sizeGrid; row++) {
		for (int column = 0; column < sizeGrid; column++) {
			if (!visited[row][column]) {
				std::vector<std::pair<int, int>> cells;
				queue.emplace(row, column);
				visited[row][column] = true;
				while (!queue.empty()) {
					auto [currentRow, currentColumn] = queue.front();
					queue.pop();
					cells.emplace_back(std::make_pair(currentRow, currentColumn));
					region[currentRow][currentColumn] = (int)cellRegion.size();
					for (int direction = 0; direction < 4; direction++) {
						int nextRow = currentRow + directionX[direction];
						int nextColumn = currentColumn + directionY[direction];
						if (nextRow >= 0 && nextRow < sizeGrid && nextColumn >= 0 && nextColumn < sizeGrid && 
							!visited[nextRow][nextColumn] && grid[currentRow][currentColumn] == grid[nextRow][nextColumn]) {
							visited[nextRow][nextColumn] = true;
							queue.emplace(nextRow, nextColumn);
						}
					}
				}
				bestOneRegion = std::max(bestOneRegion, (int)cells.size());
				cellRegion.emplace_back(cells);
			}
		}
	}
	std::vector<std::set<int>> regionAdjacent((int)cellRegion.size());
	for (const std::vector<std::pair<int, int>> &cells : cellRegion) {
		for (const auto &[row, column] : cells) {
			for (int direction = 0; direction < 4; direction++) {
				int nextRow = row + directionX[direction];
				int nextColumn = column + directionY[direction];
				if (nextRow >= 0 && nextRow < sizeGrid && nextColumn >= 0 && nextColumn < sizeGrid &&
					grid[row][column] != grid[nextRow][nextColumn]) {
					regionAdjacent[region[row][column]].insert(region[nextRow][nextColumn]);
				}
			}
		}
	}
	int bestTwoRegion = bestOneRegion;
	std::function<int(int)> indexRegion = [&](int index) {
		return grid[cellRegion[index][0].first][cellRegion[index][0].second];
	};
	std::map<std::pair<int, int>, std::set<int>> madeGroup;
	std::queue<int> queueRegion;
	for (int index = 0; index < (int)cellRegion.size(); index++) {
		for (const int &indexAdjacent : regionAdjacent[index]) {
			std::pair<int, int> currentIndex{indexRegion(index), indexRegion(indexAdjacent)};
			if (currentIndex.first > currentIndex.second) {
				std::swap(currentIndex.first, currentIndex.second);
			}
			if (!madeGroup[currentIndex].count(index)) {
				int currentSize = 0;
				queueRegion.emplace(index);
				std::vector<bool> visitedRegion((int)cellRegion.size());
				visitedRegion[index] = true;
				while (!queueRegion.empty()) {
					int currentRegion = queueRegion.front();
					queueRegion.pop();
					currentSize += (int)cellRegion[currentRegion].size();
					madeGroup[currentIndex].insert(currentRegion);
					for (const int &nextRegion : regionAdjacent[currentRegion]) {
						int nextIndex = indexRegion(nextRegion);
						if (!visitedRegion[nextRegion] && (currentIndex.first == nextIndex || currentIndex.second == nextIndex)) {
							visitedRegion[nextRegion] = true;
							queueRegion.emplace(nextRegion);
						}
					}
				}
				bestTwoRegion = std::max(bestTwoRegion, currentSize);
			}
		}
	}
	std::cout << bestOneRegion << '\n' << bestTwoRegion;
	return 0;
}