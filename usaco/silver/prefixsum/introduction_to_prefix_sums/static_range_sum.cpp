#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthArr, numQuery;
	std::cin >> lengthArr >> numQuery;
	std::vector<long long> prefixSum(lengthArr);
	for (int index = 0; index < lengthArr; index++) {
		if (index > 0) {
			prefixSum[index] = prefixSum[index - 1];
		}
		int num;
		std::cin >> num;
		prefixSum[index] += num;
	}
	while (numQuery--) {
		int left, right;
		std::cin >> left >> right;
		std::cout << prefixSum[right - 1] - (left == 0 ? 0 : prefixSum[left - 1]) << '\n';
	}
	return 0;
}