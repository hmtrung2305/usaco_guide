#include <bits/stdc++.h>

struct Bound {
	int minRow, maxRow;
	int minColumn, maxColumn;
};

int main() {
	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int sizeGrid;
	std::cin >> sizeGrid;
	std::vector<std::vector<int>> grid(sizeGrid, std::vector<int>(sizeGrid));
	std::map<int, Bound> visible;
	for (int row = 0; row < sizeGrid; row++) {
		for (int column = 0; column < sizeGrid; column++) {
			std::cin >> grid[row][column];
			if (!visible.count(grid[row][column])) {
				visible[grid[row][column]] = Bound{row, row, column, column};
			}
			Bound &bound = visible[grid[row][column]];
			bound.minRow = std::min(bound.minRow, row);
			bound.maxRow = std::max(bound.maxRow, row);
			bound.minColumn = std::min(bound.minColumn, column);
			bound.maxColumn = std::max(bound.maxColumn, column);
		}
	}
	visible.erase(0);
	int notAppear = sizeGrid * sizeGrid - (int)visible.size();
	int countOverlap = 0;
	if ((int)visible.size() > 1) {
		std::vector<std::vector<int>> prefixSumColor(sizeGrid + 1, std::vector<int>(sizeGrid + 1));
		std::set<int> validColors;
		for (const auto &[color, bound] : visible) {
			validColors.insert(color);
			prefixSumColor[bound.minRow][bound.minColumn]++;
			prefixSumColor[bound.minRow][bound.maxColumn + 1]--;
			prefixSumColor[bound.maxRow + 1][bound.minColumn]--;
			prefixSumColor[bound.maxRow + 1][bound.maxColumn + 1]++;
		}
		for (int row = 0; row < sizeGrid; row++) {
			for (int column = 0; column < sizeGrid; column++) {
				if (row > 0) {
					prefixSumColor[row][column] += prefixSumColor[row - 1][column];
				}
				if (column > 0) {
					prefixSumColor[row][column] += prefixSumColor[row][column - 1];
				}
				if (row > 0 && column > 0) {
					prefixSumColor[row][column] -= prefixSumColor[row - 1][column - 1];
				}
				if (prefixSumColor[row][column] > 1) {
					validColors.erase(grid[row][column]);
				}
			}
		}
		countOverlap = (int)validColors.size();
	}
	std::cout << notAppear + countOverlap;
	return 0;
}