#include <bits/stdc++.h>

const int MODULO = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCell, numSegment;
	std::cin >> numCell >> numSegment;
	std::vector<std::pair<int, int>> segments(numSegment);
	for (auto &[left, right] : segments) {
		std::cin >> left >> right;
	}
	std::vector<int> countWay(numCell + 1, 0);
	std::vector<int> prefixSumCountWay(numCell + 1, 0);
	countWay[1] = 1;
	prefixSumCountWay[1] = 1;
	for (int index = 2; index <= numCell; index++) {
		for (auto [leftSegment, rightSegment] : segments) {
			int left = std::max(1, index - rightSegment);
			int right = index - leftSegment;
			if (right < left) {
				continue;
			}
			countWay[index] = (1ll * countWay[index] + (prefixSumCountWay[right] - prefixSumCountWay[left - 1]) % MODULO + MODULO) % MODULO;
		}
		prefixSumCountWay[index] = (prefixSumCountWay[index - 1] + countWay[index]) % MODULO;
	}
	std::cout << countWay[numCell];
	return 0;
}