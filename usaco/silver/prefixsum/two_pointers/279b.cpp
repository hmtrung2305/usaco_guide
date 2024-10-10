#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numBook, targetTime;
	std::cin >> numBook >> targetTime;
	std::vector<int> timeBook(numBook);
	for (int &time : timeBook) {
		std::cin >> time;
	}
	int result = 0;
	for (int left = 0, right = 0, sumTime = 0; right < numBook; right++) {
		sumTime += timeBook[right];
		while (left + 1 <= right && sumTime > targetTime) {
			sumTime -= timeBook[left];
			left++;
		}
		if (sumTime <= targetTime) {
			result = std::max(result, right - left + 1);
		}
	}
	std::cout << result;
	return 0;
}