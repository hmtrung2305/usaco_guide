#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int lengthArr;
		std::cin >> lengthArr;
		std::vector<long long> d(lengthArr * 2);
		for (long long &num : d) {
			std::cin >> num;
		}
		sort(d.begin(), d.end(), std::greater<long long>());
		bool satisfyCondition = true;
		std::vector<long long> arr(lengthArr);
		for (int index = 0; index < lengthArr; index++) {
			if (d[index * 2] != d[index * 2 + 1]) {
				std::cout << "NO\n";
				satisfyCondition = false;
				break;
			}
			arr[index] = d[index * 2];
		}
		if (!satisfyCondition) {
			continue;
		}
		std::vector<long long> b(lengthArr);
		for (int index = 1; index < lengthArr; index++) {
			if (arr[index - 1] == arr[index] || (arr[index - 1] - arr[index]) % (2 * (lengthArr - index)) != 0) {
				std::cout << "NO\n";
				satisfyCondition = false;
				break;
			}
			b[index] = (arr[index - 1] - arr[index]) / (2 * (lengthArr - index));
		}
		if (!satisfyCondition) {
			continue;
		}
		for (int index = 1; index < lengthArr; index++) {
			arr[lengthArr - 1] -= 2 * index * b[index];
		}
		if (arr[lengthArr - 1] <= 0 || arr[lengthArr - 1] % (2 * lengthArr) > 0) {
			std::cout << "NO\n";
		} else {
			std::cout << "YES\n";
		}
	}
	return 0;
}