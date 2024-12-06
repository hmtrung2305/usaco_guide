#include <bits/stdc++.h>

int main() {
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numHaybale, numQuery;
	std::cin >> numHaybale >> numQuery;
	std::vector<int> positionHayBale(numHaybale);
	for (int &position : positionHayBale) {
		std::cin >> position;
	}
	sort(positionHayBale.begin(), positionHayBale.end());
	while (numQuery--) {
		int left, right;
		std::cin >> left >> right;
		std::cout << upper_bound(positionHayBale.begin(), positionHayBale.end(), right) - lower_bound(positionHayBale.begin(), positionHayBale.end(), left) << '\n';
	}
	return 0;
}