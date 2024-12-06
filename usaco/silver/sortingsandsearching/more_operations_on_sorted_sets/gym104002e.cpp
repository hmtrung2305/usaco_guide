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
	std::multiset<int> taken;
	taken.insert(std::max(arr[0], arr[1]));
	for (int index = 2; index < lengthArr; index += 2) {
		if (*taken.begin() < std::min(arr[index], arr[index + 1])) {
			taken.erase(taken.begin());
			taken.insert(arr[index]);
			taken.insert(arr[index + 1]);
		} else {
			taken.insert(std::max(arr[index], arr[index + 1]));
		}
	}
	long long result = 0;
	for (const int &num : taken) {
		result += num;
	}
	std::cout << result;
	return 0;
}