#include <bits/stdc++.h>

int main() {
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numHayBale, numCow;
	std::cin >> numHayBale >> numCow;
	std::vector<int> positionHayBale(numHayBale);
	for (int &position : positionHayBale) {
		std::cin >> position;
	}
	sort(positionHayBale.begin(), positionHayBale.end());
	int low = 0, high = 1e9, result = 1e9;
	while (low <= high) {
		int middle = low + ((high - low + 1) >> 1);
		int indexHayBale = 0;
		long long maxPosition = -1;
		int countCow = 0;
		while (indexHayBale < numHayBale) {
			if (positionHayBale[indexHayBale] <= maxPosition) {
				indexHayBale++;
			} else {
				countCow++;
				maxPosition = positionHayBale[indexHayBale] + 2 * middle;
			}
		}
		if (countCow <= numCow) {
			result = middle;
			high = middle - 1;
		} else {
			low = middle + 1;
		}
	}
	std::cout << result;
	return 0;
}