#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthArr;
	std::cin >> lengthArr;
	int num;
	std::cin >> num;
	long long result = num;
	long long maxSum = num;
	for (int index = 1; index < lengthArr; index++) {
		std::cin >> num;
		if (maxSum < 0) {
			maxSum = 0;
		}
		maxSum += num;
		result = std::max(result, maxSum);
	}
	std::cout << result;
	return 0;
}