#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int sizeGrid;
	std::cin >> sizeGrid;
	long long low = 1, high = 1e12, result = 1;
	while (low <= high) {
		long long middle = low + ((high - low + 1) >> 1);
		long long count = 0;
		for (int index = 1; index <= sizeGrid; index++) {
			count += std::min(1ll * sizeGrid, middle / index);
		}
		if (count >= ((1ll * sizeGrid * sizeGrid + 1) >> 1)) {
			result = middle;
			high = middle - 1;
		} else {
			low = middle + 1;
		}
	}
	std::cout << result;
	return 0;
}