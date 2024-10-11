#include <bits/stdc++.h>

const std::vector<int> directionX{-1, 1, 0, 0};
const std::vector<int> directionY{0, 0, -1, 1};

int main() {
	freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numRow, numSwitch;
	std::cin >> numRow >> numSwitch; // numRow = numColumn
	std::vector<std::vector<std::vector<std::pair<int, int>>>> roomSwitch(numRow, std::vector<std::vector<std::pair<int, int>>>(numRow)); 
	for (int index = 0; index < numSwitch; index++) {
		int rowSwitch, columnSwitch, rowLight, columnLight;
		std::cin >> rowSwitch >> columnSwitch >> rowLight >> columnLight;
		rowSwitch--; columnSwitch--; rowLight--; columnLight--;
		roomSwitch[rowSwitch][columnSwitch].emplace_back(rowLight, columnLight);
	}
	std::vector<std::vector<bool>> visited(numRow, std::vector<bool>(numRow));
	std::vector<std::vector<bool>> illuminate(numRow, std::vector<bool>(numRow));
	std::queue<std::pair<int, int>> queueRoom;
	queueRoom.emplace(0, 0);
	visited[0][0] = true;
	illuminate[0][0] = true;
	int countIlluminate = 1;
	while (!queueRoom.empty()) {
		auto [currentRow, currentColumn] = queueRoom.front();
		queueRoom.pop();
		for (int direction = 0; direction < 4; direction++) {
			int nextRow = currentRow + directionX[direction];
			int nextColumn = currentColumn + directionY[direction];
			if (nextRow >= 0 && nextRow < numRow && nextColumn >= 0 && nextColumn < numRow && !visited[nextRow][nextColumn] && illuminate[nextRow][nextColumn]) {
				visited[nextRow][nextColumn] = true;
				queueRoom.emplace(nextRow, nextColumn);
			}
		}
		for (const auto &[rowLight, columnLight] : roomSwitch[currentRow][currentColumn]) {
			if (!illuminate[rowLight][columnLight]) {
				illuminate[rowLight][columnLight] = true;
				countIlluminate++;
				if (!visited[rowLight][columnLight] &&
					((rowLight - 1 >= 0 && visited[rowLight - 1][columnLight]) ||
					(rowLight + 1 < numRow && visited[rowLight + 1][columnLight]) ||
					(columnLight - 1 >= 0 && visited[rowLight][columnLight - 1]) ||
					(columnLight + 1 < numRow && visited[rowLight][columnLight + 1]))) {
					visited[rowLight][columnLight] = true;
					queueRoom.emplace(rowLight, columnLight);
				}
			}
		}
	}
	std::cout << countIlluminate;
	return 0;
}