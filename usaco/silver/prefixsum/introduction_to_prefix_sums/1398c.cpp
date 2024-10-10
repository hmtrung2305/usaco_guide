#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int lengthArr;
		std::cin >> lengthArr;
		std::string str;
		std::cin >> str;
		std::map<int, int> count;
		int currentSum = 0;
		long long result = 0;
		for (int index = 0; index < (int)str.size(); index++) {
			count[currentSum]++;
			currentSum += str[index] - '0' - 1;
			result += count[currentSum];
		}
		std::cout << result << '\n';
	}
	return 0;
}