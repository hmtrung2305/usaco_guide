#include <bits/stdc++.h>

int main() {
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow, numBus, capicityBus;
	std::cin >> numCow >> numBus >> capicityBus;
	std::vector<int> timeArrive(numCow);
	for (int &time : timeArrive) {
		std::cin >> time;
	}
	sort(timeArrive.begin(), timeArrive.end());
	int low = 0, high = 2e9, result = 2e9;
	while (low <= high) {
		int middle = low + ((high - low + 1) >> 1);
		int indexCow = 0, newIndexCow = 0;
		int countBus = 0;
		while (indexCow < numCow) {
			if (indexCow == newIndexCow) {
				countBus++;
			}
			if (countBus > numBus) {
				break;
			}
			if (timeArrive[indexCow] - timeArrive[newIndexCow] > middle) {
				newIndexCow = indexCow;
			} else if (indexCow - newIndexCow + 1 == capicityBus) {
				indexCow++;
				newIndexCow = indexCow;
			} else {
				indexCow++;
			}
		}
		if (countBus <= numBus) {
			result = middle;
			high = middle - 1;
		} else {
			low = middle + 1;
		}
	}
	std::cout << result;
	return 0;
}