#include <bits/stdc++.h>

int main() {
	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow, numStore, numFarmer;
	std::cin >> numCow >> numStore >> numFarmer;
	std::vector<int> gallonCow(numCow);
	for (int &gallon : gallonCow) {
		std::cin >> gallon;
	}
	std::vector<std::pair<int, int>> stores(numStore);
	for (auto &[gallon, price] : stores) {
		std::cin >> gallon >> price;
	}
	std::vector<int> priceRent(numFarmer);
	for (int &price : priceRent) {
		std::cin >> price;
	}
	sort(gallonCow.begin(), gallonCow.end(), std::greater<int>());
	sort(stores.begin(), stores.end(), [](std::pair<int, int> store1, std::pair<int, int> store2) {
		return store1.second > store2.second;
	});
	sort(priceRent.begin(), priceRent.end(), std::greater<int>());
	int indexCow = 0, indexStore = 0, indexFarmer = 0;
	long long result = 0;
	while (indexCow < numCow) {
		int milk = gallonCow[indexCow];
		int sumSell = 0;
		int currentStore = indexStore;
		int last = 0;
		while (currentStore < numStore) {
			int sold = std::min(milk, stores[currentStore].first);
			sumSell += stores[currentStore].second * sold;
			milk -= sold;
			if (milk == 0) {
				last = sold;
				break;
			} else {
				currentStore++;
			}
		}
		if (indexFarmer >= numFarmer || sumSell > priceRent[indexFarmer]) { // sell
			result += sumSell;
			indexStore = currentStore;
			if (indexStore < numStore) {
				stores[indexStore].first -= last;
			}
			indexCow++;
		} else { // rent
			result += priceRent[indexFarmer];
			numCow--;
			indexFarmer++;
		}
	}
	std::cout << result;
	return 0;
}