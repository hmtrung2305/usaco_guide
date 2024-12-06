#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthArr, limitOperation;
	std::cin >> lengthArr >> limitOperation;
	std::vector<int> arr(lengthArr);
	for (int &num : arr) {
		std::cin >> num;
	}
	sort(arr.begin(), arr.end());
	int low = 0, high = 2e9, result = 0;
	while (low <= high) {
		int middle = low + ((high - low + 1) >> 1);
		int operationNeed = 0;
		for (int index = (lengthArr - 1) / 2; index < lengthArr; index++) {
			operationNeed += std::max(0, middle - arr[index]);
			if (operationNeed > limitOperation) {
				break;
			}
		}
		if (operationNeed <= limitOperation) {
			result = middle;
			low = middle + 1;
		} else {
			high = middle - 1;
		}
	}
	std::cout << result;
	return 0;
}