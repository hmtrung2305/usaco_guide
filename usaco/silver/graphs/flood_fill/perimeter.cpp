#include <bits/stdc++.h>

const std::vector<int> directionX{-1, 1, 0, 0};
const std::vector<int> directionY{0, 0, -1, 1};

int main() {
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numRow; 
	std::cin >> numRow; // numRow = numColumn
	std::vector<std::string> grid(numRow);
	for (std::string &row : grid) {
		std::cin >> row;
	}
	std::vector<std::vector<bool>> visited(numRow, std::vector<bool>(numRow));
	std::queue<std::pair<int, int>> queueIce;
	int maxArea = 0, minPerimeter = 1e9;
	for (int row = 0; row < numRow; row++) {
		for (int column = 0; column < numRow; column++) {
			if (grid[row][column] == '#' && !visited[row][column]) {
				queueIce.emplace(row, column);
				visited[row][column] = true;
				int area = 1, perimeter = 4;
				while (!queueIce.empty()) {
					auto [currentRow, currentColumn] = queueIce.front();
					queueIce.pop();
					for (int direction = 0; direction < 4; direction++) {
						int nextRow = currentRow + directionX[direction];
						int nextColumn = currentColumn + directionY[direction];
						if (nextRow >= 0 && nextRow < numRow && nextColumn >= 0 && nextColumn < numRow && grid[nextRow][nextColumn] == '#' && !visited[nextRow][nextColumn]) {
							visited[nextRow][nextColumn] = true;
							area++;
							perimeter += 4;
							if (nextRow > 0 && grid[nextRow - 1][nextColumn] == '#') {
								perimeter -= 2;
							}
							if (nextColumn > 0 && grid[nextRow][nextColumn - 1] == '#') {
								perimeter -= 2;
							}
							queueIce.emplace(nextRow, nextColumn);
						}
					}
				}
				if (area > maxArea) {
					maxArea = area;
					minPerimeter = perimeter;
				} else if (area == maxArea) {
					minPerimeter = std::min(minPerimeter, perimeter);
				}
			}
		}
	}
	std::cout << maxArea << ' ' << minPerimeter;
	return 0;
}