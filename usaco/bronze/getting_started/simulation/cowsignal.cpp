#include <bits/stdc++.h>

int main() {
	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numRow, numColumn, amplify;
	std::cin >> numRow >> numColumn >> amplify;
	std::vector<std::string> grid(numRow);
	for (int row = 0; row < numRow; row++) {
		std::cin >> grid[row];
	}
	for (int row = 0; row < numRow * amplify; row++) {
		for (int column = 0; column < numColumn * amplify; column++) {
			std::cout << grid[row / amplify][column / amplify];
		}
		std::cout << '\n';
	}
	return 0;
}