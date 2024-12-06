#include <bits/stdc++.h>

int main() {
	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow, numInterval;
	std::cin >> numCow >> numInterval;
	std::vector<std::pair<long long, long long>> intervals(numInterval);
	for (auto &[left, right] : intervals) {
		std::cin >> left >> right;
	}
	sort(intervals.begin(), intervals.end());
	long long low = 0, high = intervals[numInterval - 1].second - intervals[0].first + 1, result = 0;
	while (low <= high) {
		long long middle = low + ((high - low + 1) >> 1);
		int countCow = 1;
		int indexInterval = 0;
		long long currentPosition = intervals[0].first;
		while (currentPosition + middle <= intervals[numInterval - 1].second) {
			while (currentPosition + middle > intervals[indexInterval].second) {
				indexInterval++;
			}
			currentPosition = std::max(currentPosition + middle, intervals[indexInterval].first);
			countCow++;
			if (countCow == numCow) {
				break;
			}
		}
		if (countCow >= numCow) {
			result = middle;
			low = middle + 1;
		} else {
			high = middle - 1;
		}
	}
	std::cout << result;
	return 0;
}