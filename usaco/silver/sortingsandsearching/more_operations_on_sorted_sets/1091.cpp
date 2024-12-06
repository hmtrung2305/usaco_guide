#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTicket, numCustomer;
	std::cin >> numTicket >> numCustomer;
	std::multiset<int> setPriceTicket;
	for (int index = 0; index < numTicket; index++) {
		int priceTicket;
		std::cin >> priceTicket;
		setPriceTicket.insert(priceTicket);
	}
	while (numCustomer--) {
		int maxPrice;
		std::cin >> maxPrice;
		auto iterator = setPriceTicket.upper_bound(maxPrice);
		if (iterator == setPriceTicket.begin() || setPriceTicket.empty()) {
			std::cout << -1 << '\n';
		} else {
			iterator--;
			std::cout << *iterator << '\n';
			setPriceTicket.erase(iterator);
		}
	}
	return 0;
}