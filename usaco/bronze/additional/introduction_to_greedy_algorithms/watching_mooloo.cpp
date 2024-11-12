#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numDay, repay;
	std::cin >> numDay >> repay;
	long long result = 0;
	long long previousDay = 0;
	for (int index = 0; index < numDay; index++) {
		long long day;
		std::cin >> day;
		if (index == 0) {
			result = repay + 1;
		} else {
			result = std::min(result + day - previousDay, result + repay + 1);
		}
		previousDay = day;
	}
	std::cout << result;
	return 0;
}