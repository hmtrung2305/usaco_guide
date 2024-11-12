#include <bits/stdc++.h>

const int SIZE = 8;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::vector<std::vector<bool>> blocked(SIZE, std::vector<bool>(SIZE));
	for (int row = 0; row < SIZE; row++) {
		std::string rowGrid;
		std::cin >> rowGrid;
		for (int column = 0; column < SIZE; column++) {
			blocked[row][column] = (rowGrid[column] == '*');
		}
	}
	int result = 0;
	std::vector<bool> rowTaken(SIZE);
	std::vector<bool> mainDiagonal(2 * SIZE - 1, false), secondDiagonal(2 * SIZE - 1, false);
	std::function<void(int)> searchQueen = [&](int column) {
		if (column == SIZE) {
			result++;
			return;
		}
		for (int row = 0; row < SIZE; row++) {
			bool isRowOpened = !rowTaken[row];
			bool isDiagonalOpened = !mainDiagonal[row + column] && !secondDiagonal[row - column + SIZE - 1];
			if (!blocked[row][column] && isRowOpened && isDiagonalOpened) {
				rowTaken[row] = true;
				mainDiagonal[row + column] = true;
				secondDiagonal[row - column + SIZE - 1] = true;
				searchQueen(column + 1);
				rowTaken[row] = false;
				mainDiagonal[row + column] = false;
				secondDiagonal[row - column + SIZE - 1] = false;
			}
		}
	};
	searchQueen(0);
	std::cout << result;
	return 0;
}