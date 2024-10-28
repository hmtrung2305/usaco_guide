#include <bits/stdc++.h>

const std::vector<int> directionX{-1, 1, 0, 0};
const std::vector<int> directionY{0, 0, -1, 1};

int main() {
	freopen("ccski.in", "r", stdin);
	freopen("ccski.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numRow, numColumn;
	std::cin >> numRow >> numColumn;
	std::vector<std::vector<int>> height(numRow, std::vector<int>(numColumn));
	for (int row = 0; row < numRow; row++) {
		for (int column = 0; column < numColumn; column++) {
			std::cin >> height[row][column];
		}
	}
	std::vector<std::pair<int, int>> waypoints;
	for (int row = 0; row < numRow; row++) {
		for (int column = 0; column < numColumn; column++) {
			bool isWaypoint;
			std::cin >> isWaypoint;
			if (isWaypoint) {
				waypoints.emplace_back(row, column);
			}
		}
	}
	int lowDiff = 0, highDiff = 1e9, result = 0;
	std::vector<std::vector<bool>> visited;
	std::queue<std::pair<int, int>> queue;
	while (lowDiff <= highDiff) {
		int middleDiff = (lowDiff + highDiff) >> 1;
		 visited.assign(numRow, std::vector<bool>(numColumn, false));
		 queue.emplace(0, 0);
		 visited[0][0] = true;
		 while (!queue.empty()) {
		 	auto [currentRow, currentColumn] = queue.front();
		 	queue.pop();
		 	for (int direction = 0; direction < 4; direction++) {
		 		int nextRow = currentRow + directionX[direction];
		 		int nextColumn = currentColumn + directionY[direction];
		 		if (nextRow >= 0 && nextRow < numRow && nextColumn >= 0 && nextColumn < numColumn && 
		 			abs(height[currentRow][currentColumn] - height[nextRow][nextColumn]) <= middleDiff &&
		 			!visited[nextRow][nextColumn]) {
		 			visited[nextRow][nextColumn] = true;
		 			queue.emplace(nextRow, nextColumn);
		 		}
		 	}
		 }
		 bool satisfyCondition = true;
		 for (const auto &[row, column] : waypoints) {
		 	satisfyCondition &= visited[row][column];
		 }
		 if (satisfyCondition) {
		 	result = middleDiff;
		 	highDiff = middleDiff - 1;
		 } else {
		 	lowDiff = middleDiff + 1;
		 }
	}
	std::cout << result;
	return 0;
}