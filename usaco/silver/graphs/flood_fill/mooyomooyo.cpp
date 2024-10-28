#include <bits/stdc++.h>

const std::vector<int> directionX{-1, 1, 0, 0};
const std::vector<int> directionY{0, 0, -1, 1};

int main() {
	freopen("mooyomooyo.in", "r", stdin);
	freopen("mooyomooyo.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numRow, leastExist;
	std::cin >> numRow >> leastExist;
	std::vector<std::string> grid(numRow);
	for (int row = numRow - 1; row >= 0; row--) {
		std::cin >> grid[row];
	}
	std::vector<std::vector<bool>> visited;
	std::queue<std::pair<int, int>> queue;
	bool gridChanged = true;
	while (gridChanged) {
		gridChanged = false;
		visited.assign(numRow, std::vector<bool>(10, false));
		for (int row = 0; row < numRow; row++) {
			for (int column = 0; column < 10; column++) {
				if (!visited[row][column] && grid[row][column] != '0') {
					std::vector<std::pair<int, int>> component{std::make_pair(row, column)};
					visited[row][column] = true;
					queue.emplace(row, column);
					while (!queue.empty()) {
						auto [currentRow, currentColumn] = queue.front();
						queue.pop();
						for (int direction = 0; direction < 4; direction++) {
							int nextRow = currentRow + directionX[direction];
							int nextColumn = currentColumn + directionY[direction];
							if (nextRow >= 0 && nextRow < numRow && nextColumn >= 0 && nextColumn < 10 && 
								!visited[nextRow][nextColumn] && grid[nextRow][nextColumn] == grid[row][column]) {
								visited[nextRow][nextColumn] = true;
								component.emplace_back(std::make_pair(nextRow, nextColumn));
								queue.emplace(nextRow, nextColumn);
							}
						}
					}
					if ((int)component.size() >= leastExist) {
						gridChanged = true;
						for (const auto &[rowReplace, columnReplace] : component) {
							grid[rowReplace][columnReplace] = '0';
						}
					}
				}
			}
		}
		for (int column = 0; column < 10; column++) {
			std::vector<char> colorColumnGravity;
			for (int row = 0; row < numRow; row++) {
				if (grid[row][column] != '0') {
					colorColumnGravity.emplace_back(grid[row][column]);
				}
			}
			for (int row = 0; row < numRow; row++) {
				if (row < (int)colorColumnGravity.size()) {
					grid[row][column] = colorColumnGravity[row];
				} else {
					grid[row][column] = '0';
				}
			}
		}
	}
	for (int row = numRow - 1; row >= 0; row--) {
		std::cout << grid[row] << '\n';
	}
	return 0;
}