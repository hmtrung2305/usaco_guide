#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthArr;
	std::cin >> lengthArr;
	std::vector<int> arr(lengthArr);
	for (int &num : arr) {
		std::cin >> num;
	}
	sort(arr.begin(), arr.end());
	int result = 1;
	for (int index = 1; index < lengthArr; index++) {
		if (arr[index] != arr[index - 1]) {
			result++;
		}
	}
	std::cout << result;
	return 0;
}