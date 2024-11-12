#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int lengthArr;
		std::cin >> lengthArr;
		std::vector<int> arr(lengthArr);
		for (int &num : arr) {
			 std::cin >> num;
		}
		int minX = 0, maxX = 1e9;
		for (int index = 0; index < lengthArr - 1; index++) {
			int middleLeft = (arr[index] + arr[index + 1]) / 2;
			int middleRight = (arr[index] + arr[index + 1] + 1) / 2;
			if (arr[index] < arr[index + 1]) {
				maxX = std::min(maxX, middleLeft);
			}
			if (arr[index] > arr[index + 1]) {
				minX = std::max(minX, middleRight);
			}
		}
		std::cout << (minX <= maxX ? minX : -1) << '\n';
	}
	return 0;
}