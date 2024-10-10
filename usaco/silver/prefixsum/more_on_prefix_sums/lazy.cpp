#include <bits/stdc++.h>

int main() {
	freopen("lazy.in", "r", stdin);
	freopen("lazy.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int size, steps;
	std::cin >> size >> steps;
	int newSize = size * 2 - 1;
	std::vector<std::vector<int>> newGrid(newSize, std::vector<int>(newSize, -1));
	for (int row = 0; row < size; row++) {
		for (int column = 0; column < size; column++) {
			std::cin >> newGrid[row + column][size - row + column - 1];
		}
	}
	std::vector<std::vector<int>> prefixSum(newSize + 1, std::vector<int>(newSize + 1, 0));
	for (int row = 0; row < newSize; row++) {
		for (int column = 0; column < newSize; column++) {
			prefixSum[row + 1][column + 1] += prefixSum[row + 1][column];
			prefixSum[row + 1][column + 1] += prefixSum[row][column + 1];
			prefixSum[row + 1][column + 1] -= prefixSum[row][column];
			prefixSum[row + 1][column + 1] += std::max(0, newGrid[row][column]);
		}
	}
	int result = 0;
	for (int row = steps; row < newSize - steps; row++) {
		for (int column = steps; column < newSize - steps; column++) {
			if (newGrid[row][column] != -1) {
				int value = prefixSum[row + steps + 1][column + steps + 1];
				value -= prefixSum[row + steps + 1][column - steps];
				value -= prefixSum[row - steps][column + steps + 1];
				value += prefixSum[row - steps][column - steps];
				result = std::max(result, value);
			}
		}
	}
	if (steps >= size) {
		result = prefixSum[newSize][newSize];
	}
	std::cout << result;
	return 0;
}