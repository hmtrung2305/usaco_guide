#include <bits/stdc++.h>

const std::vector<int> directionX{-1, 1, 0, 0};
const std::vector<int> directionY{0, 0, -1, 1};

int main() {
	freopen("where.in", "r", stdin);
	freopen("where.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int sizeGrid;
	std::cin >> sizeGrid;
	std::vector<std::string> grid(sizeGrid);
	for (int row = 0; row < sizeGrid; row++) {
		std::cin >> grid[row];
	}
	std::vector<std::vector<bool>> visited;
	std::vector<std::array<int, 4>> listPCL;
	std::queue<std::pair<int, int>> queue;
	std::vector<int> countRegion;
	for (int rowTopLeft = 0; rowTopLeft < sizeGrid; rowTopLeft++) {
		for (int columnTopLeft = 0; columnTopLeft < sizeGrid; columnTopLeft++) {
			for (int rowBottomRight = rowTopLeft; rowBottomRight < sizeGrid; rowBottomRight++) {
				for (int columnBottomRight = columnTopLeft; columnBottomRight < sizeGrid; columnBottomRight++) {
					countRegion.assign(26, 0);
					visited.assign(sizeGrid, std::vector<bool>(sizeGrid, false));
					for (int row = rowTopLeft; row <= rowBottomRight; row++) {
						for (int column = columnTopLeft; column <= columnBottomRight; column++) {
							if (!visited[row][column]) {
								countRegion[grid[row][column] - 'A']++;
								visited[row][column] = true;
								queue.emplace(row, column);
								while (!queue.empty()) {
									auto [currentRow, currentColumn] = queue.front();
									queue.pop();
									for (int direction = 0; direction < 4; direction++) {
										int nextRow = currentRow + directionX[direction];
										int nextColumn = currentColumn + directionY[direction];
										if (nextRow >= rowTopLeft && nextRow <= rowBottomRight && nextColumn >= columnTopLeft && nextColumn <= columnBottomRight && 
											grid[nextRow][nextColumn] == grid[row][column] && !visited[nextRow][nextColumn]) {
											visited[nextRow][nextColumn] = true;
											queue.emplace(nextRow, nextColumn);
										}
									}
								}
							}
						}
					}
					int countColor = 0;
					bool hasColorOneRegion = false;
					bool hasColorMoreRegion = false;
					for (const int &frequency : countRegion) {
						if (frequency != 0) {
							countColor++;
						}
						if (frequency == 1) {
							hasColorOneRegion = true;
						}
						if (frequency > 1) {
							hasColorMoreRegion = true;
						}
					}
					if (countColor == 2 && hasColorOneRegion && hasColorMoreRegion) {
						listPCL.push_back({rowTopLeft, columnTopLeft, rowBottomRight, columnBottomRight});
					}
				}
			}
		}
	}
	int countPCL = 0;
	for (int index1 = 0; index1 < (int)listPCL.size(); index1++) {
		// auto [rowTopLeft, columnTopLeft, rowBottomRight, columnBottomRight] = listPCL[index1];
		// std::cout << rowTopLeft << ' ' << columnTopLeft << ' ' << rowBottomRight << ' ' << columnBottomRight << '\n';
		bool validPCL = true;
		for (int index2 = 0; index2 < (int)listPCL.size(); index2++) {
			if (index1 != index2) {
				if (listPCL[index1][0] >= listPCL[index2][0] && listPCL[index1][1] >= listPCL[index2][1] && 
					listPCL[index1][2] <= listPCL[index2][2] && listPCL[index1][3] <= listPCL[index2][3]) {
					validPCL = false;
					break;
				}
			}
		}
		countPCL += validPCL;
	}
	std::cout << countPCL;
	return 0;
}