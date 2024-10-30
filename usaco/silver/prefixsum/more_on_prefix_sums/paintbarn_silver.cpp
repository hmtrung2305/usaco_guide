#include <bits/stdc++.h>

const int SIZE = 1000;

int prefixSum[SIZE + 1][SIZE + 1];

int main() {
	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);
	int numRectangle, target;
	std::cin >> numRectangle >> target;
	for (int index = 0; index < numRectangle; index++) {
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		prefixSum[x1][y1]++;
		prefixSum[x1][y2]--;
		prefixSum[x2][y1]--;
		prefixSum[x2][y2]++;
	}
	int result = 0;
	for (int row = 0; row < SIZE; row++) {
		for (int column = 0; column < SIZE; column++) {
			if (row - 1 >= 0) {
				prefixSum[row][column] += prefixSum[row - 1][column];
			}
			if (column - 1 >= 0) {
				prefixSum[row][column] += prefixSum[row][column - 1];
			}
			if (row - 1 >= 0 && column - 1 >= 0) {
				prefixSum[row][column] -= prefixSum[row - 1][column - 1];
			}
			result += prefixSum[row][column] == target;
		}
	}
	std::cout << result;
	return 0;
}