#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthArr, numQuery;
	std::cin >> lengthArr >> numQuery;
	std::vector<int> arr(lengthArr);
	for (int &num : arr) {
		std::cin >> num;
	}
	std::vector<int> prefixSum(lengthArr);
	while (numQuery--) {
		int left, right;
		std::cin >> left >> right;
		prefixSum[left - 1]++;
		if (right < lengthArr) {
			prefixSum[right]--;
		}
	}
	for (int index = 1; index < lengthArr; index++) {
		prefixSum[index] += prefixSum[index - 1];
	}
	sort(prefixSum.begin(), prefixSum.end());
	sort(arr.begin(), arr.end());
	long long result = 0;
	for (int index = 0; index < lengthArr; index++) {
		result += 1ll * arr[index] * prefixSum[index];
	}
	std::cout << result;
	return 0;
}