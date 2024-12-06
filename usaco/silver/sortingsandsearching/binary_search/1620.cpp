#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numMachine, numProduct;
	std::cin >> numMachine >> numProduct;
	std::vector<int> timeMachine(numMachine);
	for (int &time : timeMachine) {
		std::cin >> time;
	}
	long long low = 0, high = 1e18, result = 1e18;
	while (low <= high) {
		long long middle = low + ((high - low + 1) >> 1);
		long long countProduct = 0;
		for (const int &time : timeMachine) {
			countProduct += middle / time;
			if (countProduct >= numProduct) {
				break;
			}
		}
		if (countProduct >= numProduct) {
			result = middle;
			high = middle - 1;
		} else {
			low = middle + 1;
		}
	}
	std::cout << result;
	return 0;
}