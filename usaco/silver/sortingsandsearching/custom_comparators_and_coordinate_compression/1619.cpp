#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCustomer;
	std::cin >> numCustomer;
	std::vector<std::pair<int, int>> timeCustomer;
	for (int index = 0; index < numCustomer; index++) {
		int left, right;
		std::cin >> left >> right;
		timeCustomer.emplace_back(left, 1);
		timeCustomer.emplace_back(right + 1, -1);
	}
	sort(timeCustomer.begin(), timeCustomer.end());
	int result = 0, current = 0;
	for (auto [time, type] : timeCustomer) {
		current += type;
		result = std::max(result, current);
	}
	std::cout << result;
	return 0;
}