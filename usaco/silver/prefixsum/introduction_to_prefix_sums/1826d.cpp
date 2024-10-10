#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int numSight;
		std::cin >> numSight;
		std::vector<int> beauty(numSight);
		for (int &sight : beauty) {
			std::cin >> sight;
		}
		std::vector<int> prefixMax(numSight), suffixMax(numSight);
		for (int sight = 0; sight < numSight; sight++) {
			prefixMax[sight] = beauty[sight] + sight;
			suffixMax[sight] = beauty[sight] - sight;
		}
		for (int sight = 1; sight < numSight; sight++) {
			prefixMax[sight] = std::max(prefixMax[sight], prefixMax[sight - 1]);
		}
		for (int sight = numSight - 2; sight >= 0; sight--) {
			suffixMax[sight] = std::max(suffixMax[sight], suffixMax[sight + 1]);
		}
		int result = 0;
		for (int sight = 1; sight < numSight - 1; sight++) {
			result = std::max(result, prefixMax[sight - 1] + beauty[sight] + suffixMax[sight + 1]);
		}
		std::cout << result << '\n';
	}
	return 0;
}