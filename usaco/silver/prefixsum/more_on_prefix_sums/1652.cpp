#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int sizeForest, numQuery;
	std::cin >> sizeForest >> numQuery;
	std::vector<std::vector<int>> prefixSum(sizeForest + 1, std::vector<int>(sizeForest + 1));
	for (int row = 0; row < sizeForest; row++) {
		for (int column = 0; column < sizeForest; column++) {
			char type;
			std::cin >> type;
			prefixSum[row + 1][column + 1] = prefixSum[row][column + 1] + prefixSum[row + 1][column] - prefixSum[row][column] + (type == '*');
		}
	}
	while (numQuery--) {
		int rowTopLeft, columnTopLeft, rowBottomRight, columnBottomRight;
		std::cin >> rowTopLeft >> columnTopLeft >> rowBottomRight >> columnBottomRight;
		std::cout << prefixSum[rowBottomRight][columnBottomRight] - 
			prefixSum[rowBottomRight][columnTopLeft - 1] - 
			prefixSum[rowTopLeft - 1][columnBottomRight] + 
			prefixSum[rowTopLeft - 1][columnTopLeft - 1] << '\n';
	}
	return 0;
}