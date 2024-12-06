#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthArr, sizeSubarr;
	std::cin >> lengthArr >> sizeSubarr;
	std::vector<int> arr(lengthArr);
	for (int &num : arr) {
		std::cin >> num;
	}
	int low = 1, high = lengthArr, result = 1;
	while (low <= high) {
		int middle = low + ((high - low + 1) >> 1);
		std::vector<int> prefix(lengthArr);
		for (int index = 0; index < lengthArr; index++) {
			prefix[index] = (index == 0 ? 0 : prefix[index - 1]) + (arr[index] >= middle ? 1 : -1);
		}
		int minPrefix = 0, maxDiff = prefix[sizeSubarr - 1];
		for (int last = sizeSubarr; last < lengthArr; last++) {
			minPrefix = std::min(minPrefix, prefix[last - sizeSubarr]);
			maxDiff = std::max(maxDiff, prefix[last] - minPrefix);
		}
		if (maxDiff > 0) {
			result = middle;
			low = middle + 1;
		} else {
			high = middle - 1;
		}
	}
	std::cout << result;
	return 0;
}