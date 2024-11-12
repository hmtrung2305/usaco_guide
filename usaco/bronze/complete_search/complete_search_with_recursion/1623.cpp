#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numApple;
	std::cin >> numApple;
	std::vector<int> weightApple(numApple);
	for (int &weight : weightApple) {
		std::cin >> weight;
	}
	long long result = 1e18;
	for (int mask = 0; mask < (1 << numApple); mask++) {
		long long weightGroup1 = 0, weightGroup2 = 0;
		for (int index = 0; index < numApple; index++) {
			if (mask & (1 << index)) {
				weightGroup1 += weightApple[index];
			} else {
				weightGroup2 += weightApple[index];
			}
		}
		result = std::min(result, (weightGroup1 - weightGroup2 > 0 ? weightGroup1 - weightGroup2 : weightGroup2 - weightGroup1));
	}
	std::cout << result;
	return 0;
}