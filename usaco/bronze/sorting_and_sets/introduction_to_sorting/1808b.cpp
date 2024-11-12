#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int numRow, numColumn;
		std::cin >> numRow >> numColumn;
		std::vector<std::vector<int>> card(numColumn, std::vector<int>(numRow));
		for (int row = 0; row < numRow; row++) {
			for (int column = 0; column < numColumn; column++) {
				std::cin >> card[column][row];
			}
		}
		long long result = 0;
		for (int column = 0; column < numColumn; column++) {
			sort(card[column].begin(), card[column].end());
			for (int row = 1; row < numRow; row++) {
				result += 1ll * row * (numRow - row) * (card[column][row] - card[column][row - 1]);
			}
		}
		std::cout << result << '\n';
	}
	return 0;
}