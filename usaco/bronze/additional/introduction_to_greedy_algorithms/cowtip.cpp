#include <bits/stdc++.h>

int main() {
	freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int sizeGrid;
	std::cin >> sizeGrid;
	std::vector<std::string> farm(sizeGrid);
	for (int row = 0; row < sizeGrid; row++) {
		std::cin >> farm[row];
	}
	int result = 0;
	for (int row = sizeGrid - 1; row >= 0; row--) {
		for (int column = sizeGrid - 1; column >= 0; column--) {
			if (farm[row][column] == '1') {
				result++;
				for (int subRow = 0; subRow <= row; subRow++) {
					for (int subColumn = 0; subColumn <= column; subColumn++) {
						farm[subRow][subColumn] = ((farm[subRow][subColumn] - '0') ^ 1) + '0';
					}
				}
			}
		}
	}
	std::cout << result;
	return 0;
}