#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthArr, targetSum;
	std::cin >> lengthArr >> targetSum;
	std::vector<std::pair<int, int>> arr(lengthArr);
	for (int index = 0; index < lengthArr; index++) {
		std::cin >> arr[index].first;
		arr[index].second = index;
	}
	sort(arr.begin(), arr.end());
	for (int middle = 1; middle < lengthArr - 1; middle++) {
		int newTargetSum = targetSum - arr[middle].first;
		for (int left = 0, right = lengthArr - 1; left < middle && middle < right; ) {
			int sum = arr[left].first + arr[right].first;
			if (sum == newTargetSum) {
				std::cout << arr[left].second + 1 << ' ' << arr[middle].second + 1 << ' ' << arr[right].second + 1;
				return 0;
			}
			if (sum > newTargetSum) {
				right--;
			} else {
				left++;
			}
		}
	}
	std::cout << "IMPOSSIBLE";
	return 0;
}