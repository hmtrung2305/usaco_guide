#include <bits/stdc++.h>

const std::vector<int> directionX{-1, 1, 0, 0};
const std::vector<int> directionY{0, 0, -1, 1};

int main() {
	freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int sizeGrid, numCow, numRoad;
	std::cin >> sizeGrid >> numCow >> numRoad;
	std::vector<std::vector<int>> grid(sizeGrid, std::vector<int>(sizeGrid));
	std::map<std::pair<std::pair<int, int>, std::pair<int, int>>, bool> isRoad;
	for (int road = 0; road < numRoad; road++) {
		int row1, column1, row2, column2;
		std::cin >> row1 >> column1 >> row2 >> column2;
		row1--; column1--; row2--; column2--;
		isRoad[std::make_pair(std::make_pair(row1, column1), std::make_pair(row2, column2))] = true;
		isRoad[std::make_pair(std::make_pair(row2, column2), std::make_pair(row1, column1))] = true;
	}
	std::vector<std::vector<bool>> hasCow(sizeGrid, std::vector<bool>(sizeGrid));
	for (int index = 0; index < numCow; index++) {
		int x, y;
		std::cin >> x >> y;
		x--; y--;
		hasCow[x][y] = true;
	}
	std::queue<std::pair<int, int>> queue;
	std::vector<std::vector<bool>> visited(sizeGrid, std::vector<bool>(sizeGrid));
	std::vector<int> amountCowRegion;
	for (int row = 0; row < sizeGrid; row++) {
		for (int column = 0; column < sizeGrid; column++) {
			if (!visited[row][column]) {
				visited[row][column] = true;
				queue.emplace(row, column);
				int countCow = hasCow[row][column];
				while (!queue.empty()) {
					auto [currentRow, currentColumn] = queue.front();
					queue.pop();
					for (int direction = 0; direction < 4; direction++) {
						int nextRow = currentRow + directionX[direction];
						int nextColumn = currentColumn + directionY[direction];
						if (nextRow >= 0 && nextRow < sizeGrid && nextColumn >= 0 && nextColumn < sizeGrid && 
							!isRoad[{{currentRow, currentColumn}, {nextRow, nextColumn}}] && !visited[nextRow][nextColumn]) {
							countCow += hasCow[nextRow][nextColumn];
							visited[nextRow][nextColumn] = true;
							queue.emplace(nextRow, nextColumn);
						}
					}
				}
				amountCowRegion.emplace_back(countCow);
			}
		}
	}
	int result = 0;
	int sum = 0;
	for (const int &amount : amountCowRegion) {
		result += sum * amount;
		sum += amount;
	}
	std::cout << result;
	return 0;
}