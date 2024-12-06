#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthArr;
	long long maxOperation;
	std::cin >> lengthArr >> maxOperation;
	std::vector<int> arr(lengthArr);
	for (int &num : arr) {
		std::cin >> num;
	}
	sort(arr.begin(), arr.end());
	std::vector<long long> prefixSum(lengthArr + 1);
	for (int index = 0; index < lengthArr; index++) {
		prefixSum[index + 1] = prefixSum[index] + arr[index];
	}
	int low = 0, high = arr.back() - arr[0], result = high;
	while (low <= high) {
		int middle = low + ((high - low + 1) >> 1);
		bool satisfyCondition = false;
		for (int left = 0; left < lengthArr; left++) {
			int right = upper_bound(arr.begin(), arr.end(), arr[left] + middle) - arr.begin();
			long long operationNeeded =
				1ll * left * arr[left] - prefixSum[left] + 
				prefixSum[lengthArr] - prefixSum[right] - 1ll * (lengthArr - right) * (arr[left] + middle);
			if (operationNeeded <= maxOperation) {
				satisfyCondition = true;
			}
		}
		if (!satisfyCondition) {
			for (int right = 0; right < lengthArr; right++) {
				int left = lower_bound(arr.begin(), arr.end(), arr[right] - middle) - arr.begin();
				long long operationNeeded =
					1ll * left * (arr[right] - middle) - prefixSum[left] + 
					prefixSum[lengthArr] - prefixSum[right] - 1ll * (lengthArr - right) * arr[right];
				if (operationNeeded <= maxOperation) {
					satisfyCondition = true;
				}
			}
		}
		if (satisfyCondition) {
			result = middle;
			high = middle - 1;
		} else {
			low = middle + 1;
		}
	}
	std::cout << result;
	return 0;
}