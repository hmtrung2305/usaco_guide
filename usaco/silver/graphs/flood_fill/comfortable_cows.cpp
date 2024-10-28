#include <bits/stdc++.h>

const int ROW = 2100;
const std::vector<int> directionX{-1, 1, 0, 0};
const std::vector<int> directionY{0, 0, -1, 1};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	int totalCow = 0;
	std::vector<std::vector<bool>> placedCow(ROW, std::vector<bool>(ROW));
	std::queue<std::pair<int, int>> queuePlaceCow;
	std::function<void(int, int)> reEvaluate = [&](int currentRow, int currentColumn) {
		if (!placedCow[currentRow][currentColumn]) {
			return;
		}
		int countAdjacent = 0;
		for (int direction = 0; direction < 4; direction++) {
			countAdjacent += placedCow[currentRow + directionX[direction]][currentColumn + directionY[direction]];
		}
		if (countAdjacent == 3) {
			for (int direction = 0; direction < 4; direction++) {
				int nextRow = currentRow + directionX[direction];
				int nextColumn = currentColumn + directionY[direction];
				if (!placedCow[nextRow][nextColumn]) {
					queuePlaceCow.emplace(nextRow, nextColumn);
				}
			}
		}
	};
	for (int initialCow = 1; initialCow <= numCow; initialCow++) {
		std::pair<int, int> positionCow;
		std::cin >> positionCow.first >> positionCow.second;
		positionCow.first += 1000;
		positionCow.second += 1000;
		queuePlaceCow.emplace(positionCow);
		while (!queuePlaceCow.empty()) {
			auto [currentRow, currentColumn] = queuePlaceCow.front();
			queuePlaceCow.pop();
			if (placedCow[currentRow][currentColumn]) {
				continue;
			}
			totalCow++;
			placedCow[currentRow][currentColumn] = true;
			reEvaluate(currentRow, currentColumn);
			for (int direction = 0; direction < 4; direction++) {
				reEvaluate(currentRow + directionX[direction], currentColumn + directionY[direction]);
			}
		}
		std::cout << totalCow - initialCow << '\n';
	}
	return 0;
}