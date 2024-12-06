/*
practicing - but sickness..
*/
#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int lengthArr;
		std::cin >> lengthArr;
		lengthArr <<= 1;
		std::vector<int> arr(lengthArr);
		for (int &num : arr) {
			std::cin >> num;
		}
		sort(arr.begin(), arr.end());
		bool satisfyCondition = false;
		std::vector<std::pair<int, int>> pairRemove;
		for (int index = 0; index < lengthArr - 1; index++) {
			pairRemove.clear();
			int sumRemove = arr[index] + arr[lengthArr - 1];
			std::multiset<int> setNum;
			for (const int &num : arr) {
				setNum.insert(num);
			}
			while (!setNum.empty()) {
				int currentMax = *setNum.rbegin();
				setNum.erase(setNum.find(currentMax));
				if (setNum.find(sumRemove - currentMax) == setNum.end()) {
					break;
				}
				setNum.erase(setNum.find(sumRemove - currentMax));
				pairRemove.push_back({currentMax, sumRemove - currentMax});
				sumRemove = currentMax;
			}
			if (setNum.empty()) {
				satisfyCondition = true;
				std::cout << "YES" << '\n' << arr[index] + arr[lengthArr - 1] << '\n';
				for (const auto &[num1, num2] : pairRemove) {
					std::cout << num1 << ' ' << num2 << '\n';
				}
				break;
			}
		}
		if (!satisfyCondition) {
			std::cout << "NO" << '\n';
		}
	}
	return 0;
}
