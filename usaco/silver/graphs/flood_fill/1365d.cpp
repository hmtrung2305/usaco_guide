#include <bits/stdc++.h>

const std::vector<int> directionX{-1, 1, 0, 0};
const std::vector<int> directionY{0, 0, -1, 1};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int numRow, numColumn;
		std::cin >> numRow >> numColumn;
		std::vector<std::string> grid(numRow);
		for (std::string &row : grid) {
			std::cin >> row;
		}
		for (int row = 0; row < numRow; row++) {
			for (int column = 0; column < numColumn; column++) {
				if (grid[row][column] == 'B') {
					for (int direction = 0; direction < 4; direction++) {
						int nextRow = row + directionX[direction];
						int nextColumn = column + directionY[direction]; 
						if (nextRow >= 0 && nextRow < numRow && nextColumn >= 0 && nextColumn < numColumn && grid[nextRow][nextColumn] == '.') {
							grid[nextRow][nextColumn] = '#';
						}
					}
				}
			}
		}
		std::vector<std::vector<bool>> visited(numRow, std::vector<bool>(numColumn));
		std::queue<std::pair<int, int>> queue;
		if (grid[numRow - 1][numColumn - 1] == '.') {
			queue.emplace(numRow - 1, numColumn - 1);
			visited[numRow - 1][numColumn - 1] = true;
		}
		while (!queue.empty()) {
			auto [currentRow, currentColumn] = queue.front();
			queue.pop();
			for (int direction = 0; direction < 4; direction++) {
				int nextRow = currentRow + directionX[direction];
				int nextColumn = currentColumn + directionY[direction];
				if (nextRow >= 0 && nextRow < numRow && nextColumn >= 0 && nextColumn < numColumn && grid[nextRow][nextColumn] != '#' && !visited[nextRow][nextColumn]) {
					visited[nextRow][nextColumn] = true;
					queue.emplace(nextRow, nextColumn);
				}
			}
		}
		bool satisfyCondition = true;
		for (int row = 0; row < numRow; row++) {
			for (int column = 0; column < numColumn; column++) {
				if ((grid[row][column] == 'B' && visited[row][column]) || (grid[row][column] == 'G' && !visited[row][column])) {
					satisfyCondition = false;
					break;
				}
			}
			if (satisfyCondition == false) {
				break;
			}
		}
		std::cout << (satisfyCondition ? "Yes" : "No") << '\n';
	}
	return 0;
}