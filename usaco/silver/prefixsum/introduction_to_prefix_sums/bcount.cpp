#include <bits/stdc++.h>

int main() {
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow, numQuery;
	std::cin >> numCow >> numQuery;
	std::vector<std::vector<int>> prefixSumCow(numCow, std::vector<int>(3));
	for (int index = 0; index < numCow; index++) {
		int typeCow;
		std::cin >> typeCow;
		if (index != 0) {
			for (int type = 0; type < 3; type++) {
				prefixSumCow[index][type] = prefixSumCow[index - 1][type];
			}
		}
		prefixSumCow[index][typeCow - 1]++;
	}
	while (numQuery--) {
		int left, right;
		std::cin >> left >> right;
		for (int type = 0; type < 3; type++) {
			std::cout << prefixSumCow[right - 1][type] - (left == 1 ? 0 : prefixSumCow[left - 2][type]);
			if (type < 2) {
				std::cout << ' ';
			}
		}
		if (numQuery > 0) {
			std::cout << '\n';
		}
	}
	return 0;
}