#include <bits/stdc++.h>

int main() {
	freopen("loan.in", "r", stdin);
	freopen("loan.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	long long targetGallon, limitDay, leastGallonGive;
	std::cin >> targetGallon >> limitDay >> leastGallonGive;
	long long low = 1, high = 1e12, result = 1;
	while (low <= high) {
		long long middle = low + ((high - low + 1) >> 1);
		long long gallonAlreadyGiven = 0;
		bool satisfyCondition = false;
		long long currentDay = limitDay;
		while (currentDay > 0 && gallonAlreadyGiven < targetGallon) {
			long long currentGive = (targetGallon - gallonAlreadyGiven) / middle;
			if (currentGive < leastGallonGive) {
				long long dayLeftover = (targetGallon - gallonAlreadyGiven + leastGallonGive - 1) / leastGallonGive;
				satisfyCondition = (dayLeftover <= currentDay);
				break;
			}
			long long maxMatch = targetGallon - middle * currentGive;
			long long numDay = (maxMatch - gallonAlreadyGiven) / currentGive + 1;
			if (numDay > currentDay) {
				numDay = currentDay;
			}
			gallonAlreadyGiven += currentGive * numDay;
			currentDay -= numDay;
		}
		satisfyCondition |= gallonAlreadyGiven >= targetGallon;
		if (satisfyCondition) {
			result = middle;
			low = middle + 1;
		} else {
			high = middle - 1;
		}
	}
	std::cout << result;
	return 0;
}