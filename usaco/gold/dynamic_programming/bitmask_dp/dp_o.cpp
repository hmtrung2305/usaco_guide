#include <bits/stdc++.h>

const int MODULO = 1e9 + 7;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numPair;
	std::cin >> numPair;
	std::vector<std::vector<int>> canPair(numPair, std::vector<int>(numPair));
	for (int men = 0; men < numPair; men++) {
		for (int woman = 0; woman < numPair; woman++) {
			std::cin >> canPair[men][woman];
		}
	}
	std::vector<int> countWay(1 << numPair);
	countWay[0] = 1;
	for (int bitmask = 0; bitmask < (1 << numPair); bitmask++) {
		int countPair = __builtin_popcount(bitmask);
		for (int woman = 0; woman < numPair; woman++) {
			if (((bitmask & (1 << woman)) > 0) || canPair[countPair][woman] == 0) {
				continue;
			}
			countWay[bitmask | (1 << woman)] = (countWay[bitmask | (1 << woman)] + countWay[bitmask]) % MODULO;
		}
	}
	std::cout << countWay[(1 << numPair) - 1];
	return 0;
}