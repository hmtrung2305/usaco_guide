#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numRow, numColumn;
	std::cin >> numRow >> numColumn;
	std::vector<std::string> grid(numRow);
	for (std::string &row : grid) {
		std::cin >> row;
	}
	std::vector<int> directionX{-1, 1, 0, 0};
	std::vector<int> directionY{0, 0, -1, 1};
	int countFloor = 0;
	std::queue<std::pair<int, int>> queueFloor;
	for (int row = 0; row < numRow; row++) {
		for (int column = 0; column < numColumn; column++) {
			if (grid[row][column] == '.') {
				countFloor++;
				grid[row][column] = '#';
				queueFloor.emplace(row, column);
				while (!queueFloor.empty()) {
					auto [currentRow, currentColumn] = queueFloor.front();
					queueFloor.pop();
					for (int direction = 0; direction < 4; direction++) {
						int nextRow = currentRow + directionX[direction];
						int nextColumn = currentColumn + directionY[direction];
						if (nextRow >= 0 && nextRow < numRow && nextColumn >= 0 && nextColumn < numColumn && grid[nextRow][nextColumn] == '.') {
							grid[nextRow][nextColumn] = '#';
							queueFloor.emplace(nextRow, nextColumn);
						}
					}
				}
			}
		}
	}
	std::cout << countFloor;
	return 0;
}