#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int numDepartment;
		std::cin >> numDepartment;
		std::vector<std::pair<int, int>> priceGift(numDepartment);
		for (int index = 0; index < numDepartment; index++) {
			std::cin >> priceGift[index].first >> priceGift[index].second;
		}
		sort(priceGift.begin(), priceGift.end(), [](const std::pair<int, int> &leftSide, const std::pair<int, int> &rightSide) {
			if (leftSide.second == rightSide.second) {
				return leftSide.first < rightSide.first;
			}
			return leftSide.second > rightSide.second;
		});
		std::multiset<int> setPriceFirst;
		for (const auto &[priceFirst, priceSecond] : priceGift) {
			setPriceFirst.insert(priceFirst);
		}
		int result = 1e9;
		for (int index = 1; index < numDepartment; index++) {
			result = std::min(result, abs(priceGift[index].first - priceGift[0].second));
		}
		int maxPriceFirst = -1e9;
		for (int index = 0; index < numDepartment; index++) {
			setPriceFirst.erase(setPriceFirst.find(priceGift[index].first));
			if (index == 0) {
				maxPriceFirst = priceGift[index].first;
			} else {
				result = std::min(result, abs(maxPriceFirst - priceGift[index].second));
				auto iterator = setPriceFirst.lower_bound(priceGift[index].second);
				if (iterator != setPriceFirst.end() && *iterator >= maxPriceFirst) {
					result = std::min(result, *iterator - priceGift[index].second);
				}
				if (iterator != setPriceFirst.begin() && *prev(iterator) >= maxPriceFirst) {
					result = std::min(result, abs(*prev(iterator) - priceGift[index].second));
				}
				maxPriceFirst = std::max(maxPriceFirst, priceGift[index].first);
			}
		}
		std::cout << result << '\n';
	}
	return 0;
}