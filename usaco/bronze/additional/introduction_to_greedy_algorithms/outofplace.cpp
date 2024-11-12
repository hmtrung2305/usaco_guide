#include <bits/stdc++.h>

int main() {
	freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	std::vector<int> heightCow(numCow);
	for (int &height : heightCow) {
		std::cin >> height;
	}
	std::vector<int> heightCowSorted(heightCow);
	sort(heightCowSorted.begin(), heightCowSorted.end());
	int minSwap = 0;
	for (int index = 0; index < numCow; index++) {
		minSwap += (heightCow[index] != heightCowSorted[index]);
	}
	std::cout << std::max(0, minSwap - 1);
	return 0;
}