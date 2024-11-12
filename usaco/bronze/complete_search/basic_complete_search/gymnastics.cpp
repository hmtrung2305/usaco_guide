#include <bits/stdc++.h>

int main() {
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numSession, numCow;
	std::cin >> numSession >> numCow;
	std::vector<std::vector<bool>> better(numCow, std::vector<bool>(numCow, false));
	for (int session = 0; session < numSession; session++) {
		std::vector<int> ranking(numCow);
		for (int &rank : ranking) {
			std::cin >> rank;
			rank--;
		}
		for (int left = 0; left < numCow; left++) {
			for (int right = left + 1; right < numCow; right++) {
				better[ranking[right]][ranking[left]] = true;
			}
		}
	}
	int countBetterPair = 0;
	for (int left = 0; left < numCow; left++) {
		for (int right = left + 1; right < numCow; right++) {
			countBetterPair += !better[left][right] || !better[right][left];
		}
	}
	std::cout << countBetterPair;
	return 0;
}