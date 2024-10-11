#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthArr, targetSum;
	std::cin >> lengthArr >> targetSum;
	std::vector<int> arr(lengthArr);
	for (int &num : arr) {
		std::cin >> num;
	}
	int result = 0;
	for (int left = 0, right = 0, sum = 0; right < lengthArr; right++) {
		sum += arr[right];
		while (left + 1 <= right && targetSum < sum) {
			sum -= arr[left];
			left++;
		}
		result += (sum == targetSum);
	}
	std::cout << result;
	return 0;
}