#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numRow, numColumn;
	std::cin >> numRow >> numColumn;
	std::vector<std::string> grid(numRow);
	std::pair<int, int> startPoint, targetPoint;
	for (int row = 0; row < numRow; row++) {
		std::cin >> grid[row];
		for (int column = 0; column < numColumn; column++) {
			if (grid[row][column] == 'A') {
				startPoint = std::make_pair(row, column);
			} else if (grid[row][column] == 'B') {
				targetPoint = std::make_pair(row, column);
			}
		}
	}
	std::queue<std::pair<int, int>> queuePoint;
	std::vector<std::vector<int>> distance(numRow, std::vector<int>(numColumn, -1));
	std::vector<std::vector<int>> tracePath(numRow, std::vector<int>(numColumn, -1));
	std::vector<int> directionX{-1, 1, 0, 0};
	std::vector<int> directionY{0, 0, -1, 1};
	queuePoint.emplace(startPoint);
	distance[startPoint.first][startPoint.second] = 0;
	while (!queuePoint.empty()) {
		auto [currentRow, currentColumn] = queuePoint.front();
		queuePoint.pop();
		for (int direction = 0; direction < 4; direction++) {
			int nextRow = currentRow + directionX[direction];
			int nextColumn = currentColumn + directionY[direction];
			if (nextRow >= 0 && nextRow < numRow && nextColumn >= 0 && nextColumn < numColumn && grid[nextRow][nextColumn] != '#' && distance[nextRow][nextColumn] == -1) {
				distance[nextRow][nextColumn] = distance[currentRow][currentColumn] + 1;
				tracePath[nextRow][nextColumn] = direction;
				queuePoint.emplace(nextRow, nextColumn);
			}
		}
	}
	if (distance[targetPoint.first][targetPoint.second] == -1) {
		std::cout << "NO";
	} else {
		std::cout << "YES" << '\n' << distance[targetPoint.first][targetPoint.second] << '\n';
		std::string path = "";
		auto [row, column] = targetPoint;
		std::string ways = "UDLR";
		while (std::make_pair(row, column) != startPoint) {
			path += ways[tracePath[row][column]];
			int minusX = directionX[tracePath[row][column]];
			int minusY = directionY[tracePath[row][column]];
			row -= minusX;
			column -= minusY;
		}
		reverse(path.begin(), path.end());
		std::cout << path;
	}
	return 0;
}