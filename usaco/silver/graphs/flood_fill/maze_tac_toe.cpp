#include <bits/stdc++.h>

const int SIZE = 26;
const std::vector<int> directionX{-1, 1, 0, 0};
const std::vector<int> directionY{0, 0, -1, 1};

bool visited[SIZE][SIZE][19683]; // 3^9

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int sizeGrid;
	std::cin >> sizeGrid;
	std::vector<std::vector<int>> grid(sizeGrid, std::vector<int>(sizeGrid));
	std::vector<std::vector<std::pair<int, int>>> positionMark(sizeGrid, std::vector<std::pair<int, int>>(sizeGrid));
	for (int row = 0; row < sizeGrid; row++) {
		std::string str;
		std::cin >> str;
		for (int column = 0, power = 0; column < sizeGrid; column++, power += 3) {
			if (str[power] == '#') {
				grid[row][column] = 1;
			} else if (str[power] == 'B') {
				grid[row][column] = -1;
			} else if (str[power] == 'O' || str[power] == 'M') {
				grid[row][column] = str[power] == 'O' ? 2 : 3;
				positionMark[row][column] = std::make_pair(str[power + 1] - '0' - 1, str[power + 2] - '0' - 1);
			}
		}
	}
	std::vector<int> power3(10);
	power3[0] = 1;
	for (int index = 1; index < 10; index++) {
		power3[index] = power3[index - 1] * 3;
	}
	std::function<int(int, int)> getIndex = [](int row, int column) {
		return 3 * row + column;
	};
	std::function<int(int, int)> getBit = [&](int mask, int index) {
		return mask / power3[index] % 3;
	};
	std::vector<int> isWinStatus(power3[9]);
	for (int status = 0; status < power3[9]; status++) {
		int mainDiagonal = 0, secondDiagonal = 0;
		bool isWin = false;
		for (int row = 0; row < 3; row++) {
			int horizontal = 0, vertical = 0;
			for (int column = 0; column < 3; column++) {
				horizontal = horizontal * 10 + getBit(status, getIndex(row, column));
				vertical = vertical * 10 + getBit(status, getIndex(column, row));
			}
			if (horizontal == 112 || horizontal == 211 || vertical == 112 || vertical == 211) {
				isWin = true;
				break;
			}
			mainDiagonal = mainDiagonal * 10 + getBit(status, getIndex(row, row));
			secondDiagonal = secondDiagonal * 10 + getBit(status, getIndex(2 - row, row));
		}
		isWin |= (mainDiagonal == 112 || mainDiagonal == 211 || secondDiagonal == 112 || secondDiagonal == 211);
		isWinStatus[status] = isWin;
	}
	std::pair<int, int> start{-1, -1};
	for (int row = 0; row < sizeGrid; row++) {
		for (int column = 0; column < sizeGrid; column++) {
			if (grid[row][column] == -1) {
				start = std::make_pair(row, column);
				break;
			}
		}
		if (start.first != -1) {
			break;
		}
	}
	std::queue<std::tuple<int, int, int>> queue;
	queue.emplace(start.first, start.second, 0);
	visited[start.first][start.second][0] = true;
	while (!queue.empty()) {
		auto [currentRow, currentColumn, currentStatus] = queue.front();
		queue.pop();
		if (isWinStatus[currentStatus]) {
			continue;
		}
		for (int direction = 0; direction < 4; direction++) {
			int nextRow = currentRow + directionX[direction];
			int nextColumn = currentColumn + directionY[direction];
			if (nextRow >= 0 && nextRow < sizeGrid && nextColumn >= 0 && nextColumn < sizeGrid && grid[nextRow][nextColumn] != 1) {
				if (grid[nextRow][nextColumn] < 1 && !visited[nextRow][nextColumn][currentStatus]) {
					visited[nextRow][nextColumn][currentStatus] = true;
					queue.emplace(nextRow, nextColumn, currentStatus);
				}
				if (grid[nextRow][nextColumn] > 1) {
					int nextStatus = currentStatus;
					int index = getIndex(positionMark[nextRow][nextColumn].first, positionMark[nextRow][nextColumn].second);
					if (getBit(currentStatus, index) == 0) {
						nextStatus += (grid[nextRow][nextColumn] - 1) * power3[index];
					}
					if (!visited[nextRow][nextColumn][nextStatus]) {
						visited[nextRow][nextColumn][nextStatus] = true;
						queue.emplace(nextRow, nextColumn, nextStatus);
					}
				}
			}
		}
	}
	int result = 0;
	for (int status = 0; status < power3[9]; status++) {
		bool won = false;
		for (int row = 0; row < sizeGrid; row++) {
			for (int column = 0; column < sizeGrid; column++) {
				if (visited[row][column][status] && isWinStatus[status]) {
					won = true;
					result++;
					break;
				}
			}
			if (won) {
				break;
			}
		}
	}
	std::cout << result;
	return 0;
}