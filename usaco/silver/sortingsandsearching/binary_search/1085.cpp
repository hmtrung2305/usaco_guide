#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthArr, numSubarr;
	std::cin >> lengthArr >> numSubarr;
	std::vector<int> arr(lengthArr);
	for (int &num : arr) {
		std::cin >> num;
	}
	int maxArr = *std::max_element(arr.begin(), arr.end());
	long long low = maxArr, high = 1ll * maxArr * lengthArr, result = 1ll * maxArr * lengthArr;
	while (low <= high) {
		long long middle = low + ((high - low + 1) >> 1);
		int countSub = 1;
		long long currentSum = 0;
		for (const int &num : arr) {
			currentSum += num;
			if (currentSum > middle) {
				currentSum = num;
				countSub++;
			}
		}
		if (countSub <= numSubarr) {
			result = middle;
			high = middle - 1;
		} else {
			low = middle + 1;
		}
	}
	std::cout << result;
	return 0;
}