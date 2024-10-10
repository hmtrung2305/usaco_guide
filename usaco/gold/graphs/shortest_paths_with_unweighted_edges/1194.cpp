#include <bits/stdc++.h>

const std::vector<int> directionX{-1, 1, 0, 0};
const std::vector<int> directionY{0, 0, -1, 1};
const std::string ways = "UDLR";

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numRow, numColumn;
	std::cin >> numRow >> numColumn;
	std::vector<std::string> grid(numRow);
	std::pair<int, int> startPoint;
	std::queue<std::pair<int, int>> queueMonster;
	std::vector<std::vector<int>> distanceMonster(numRow, std::vector<int>(numColumn, 1e9));
	for (int row = 0; row < numRow; row++) {
		std::cin >> grid[row];
		for (int column = 0; column < numColumn; column++) {
			if (grid[row][column] == 'A') {
				startPoint = std::make_pair(row, column);
			} else if (grid[row][column] == 'M') {
				distanceMonster[row][column] = 0;
				queueMonster.emplace(row, column);
			}
		}
	}
	while (!queueMonster.empty()) {
		auto [currentRow, currentColumn] = queueMonster.front();
		queueMonster.pop();
		for (int direction = 0; direction < 4; direction++) {
			int nextRow = currentRow + directionX[direction];
			int nextColumn = currentColumn + directionY[direction];
			if (nextRow >= 0 && nextRow < numRow && nextColumn >= 0 && nextColumn < numColumn && grid[nextRow][nextColumn] != '#' && distanceMonster[nextRow][nextColumn] == 1e9) {
				distanceMonster[nextRow][nextColumn] = distanceMonster[currentRow][currentColumn] + 1;
				queueMonster.emplace(nextRow, nextColumn);
			}
		}
	}
	std::queue<std::pair<int, int>> queuePosition;
	std::vector<std::vector<int>> distance(numRow, std::vector<int>(numColumn, -1));
	distance[startPoint.first][startPoint.second] = 0;
	std::pair<int, int> targetPoint{-1, -1};
	queuePosition.emplace(startPoint);
	std::vector<std::vector<int>> tracePath(numRow, std::vector<int>(numColumn, -1));
	while (!queuePosition.empty()) {
		auto [currentRow, currentColumn] = queuePosition.front();
		if (currentRow == 0 || currentRow == numRow - 1 || currentColumn == 0 || currentColumn == numColumn - 1) {
			targetPoint = std::make_pair(currentRow, currentColumn);
			break;
		}
		queuePosition.pop();
		for (int direction = 0; direction < 4; direction++) {
			int nextRow = currentRow + directionX[direction];
			int nextColumn = currentColumn + directionY[direction];
			if (nextRow >= 0 && nextRow < numRow && nextColumn >= 0 && nextColumn < numColumn && grid[nextRow][nextColumn] != '#' && distance[nextRow][nextColumn] == -1 
				&& distanceMonster[nextRow][nextColumn] > distance[currentRow][currentColumn] + 1) {
				distance[nextRow][nextColumn] = distance[currentRow][currentColumn] + 1;
				tracePath[nextRow][nextColumn] = direction;
				queuePosition.emplace(nextRow, nextColumn);
			}
		}
	}
	if (targetPoint.first == -1) {
		std::cout << "NO";
	} else {
		std::cout << "YES" << '\n' << distance[targetPoint.first][targetPoint.second] << '\n';
		auto [row, column] = targetPoint;
		std::string path = "";
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