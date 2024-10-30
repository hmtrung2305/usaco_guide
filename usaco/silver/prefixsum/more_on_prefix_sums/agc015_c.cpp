#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numRow, numColumn, numQuery;
	std::cin >> numRow >> numColumn >> numQuery;
	std::vector<std::string> grid(numRow);
	std::vector<std::vector<int>> prefixPoint(numRow + 1, std::vector<int>(numColumn + 1));
	std::vector<std::vector<int>> prefixAdjacentRow(numRow + 1, std::vector<int>(numColumn + 1));
	std::vector<std::vector<int>> prefixAdjacentColumn(numRow + 1, std::vector<int>(numColumn + 1));
	for (int row = 0; row < numRow; row++) {
		std::cin >> grid[row];
		for (int column = 0; column < numColumn; column++) {
			prefixPoint[row + 1][column + 1] = (grid[row][column] == '1') + prefixPoint[row][column + 1] + prefixPoint[row + 1][column] - prefixPoint[row][column];
			prefixAdjacentRow[row + 1][column + 1] = (grid[row][column] == '1' && (row > 0 ? grid[row - 1][column] == '1' : false)) + 
				prefixAdjacentRow[row][column + 1] + prefixAdjacentRow[row + 1][column] - prefixAdjacentRow[row][column];
			prefixAdjacentColumn[row + 1][column + 1] = (grid[row][column] == '1' && (column > 0 ? grid[row][column - 1] == '1' : false)) + 
				prefixAdjacentColumn[row][column + 1] + prefixAdjacentColumn[row + 1][column] - prefixAdjacentColumn[row][column];
		}
	}
	while (numQuery--) {
		int rowTopLeft, columnTopLeft, rowBottomRight, columnBottomRight;
		std::cin >> rowTopLeft >> columnTopLeft >> rowBottomRight >> columnBottomRight;
		int totalPoint = 
			prefixPoint[rowBottomRight][columnBottomRight] - 
			prefixPoint[rowBottomRight][columnTopLeft - 1] - 
			prefixPoint[rowTopLeft - 1][columnBottomRight] + 
			prefixPoint[rowTopLeft - 1][columnTopLeft - 1];
		int totalAdjacentRow = 
			prefixAdjacentRow[rowBottomRight][columnBottomRight] - 
			prefixAdjacentRow[rowBottomRight][columnTopLeft - 1] - 
			prefixAdjacentRow[rowTopLeft][columnBottomRight] + 
			prefixAdjacentRow[rowTopLeft][columnTopLeft - 1];
		int totalAdjacentColumn = 
			prefixAdjacentColumn[rowBottomRight][columnBottomRight] - 
			prefixAdjacentColumn[rowBottomRight][columnTopLeft] - 
			prefixAdjacentColumn[rowTopLeft - 1][columnBottomRight] + 
			prefixAdjacentColumn[rowTopLeft - 1][columnTopLeft];
		std::cout << totalPoint - totalAdjacentRow - totalAdjacentColumn << '\n';
	}
	return 0;
}