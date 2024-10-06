#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int numBranch, base, height;
		std::cin >> numBranch >> base >> height;
		std::vector<int> positions(numBranch);
		for (int &position : positions) {
			std::cin >> position;
		}
		double result = (double)base * height / 2.0 * numBranch;
		for (int index = 1; index < numBranch; index++) {
			int diff = height - (positions[index] - positions[index - 1]);
			if (diff > 0) {
				result -= (double)diff * diff / height * base / 2.0;
			}
		}
		std::cout << std::fixed << std::setprecision(6) << result << '\n';
	}
	return 0;
}