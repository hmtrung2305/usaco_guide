#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::string str;
	std::cin >> str;
	std::vector<std::vector<int>> prefixSum((int)str.size() + 1, std::vector<int>(26, 0));
	for (int index = 1; index <= (int)str.size(); index++) {
		for (int letter = 0; letter < 26; letter++) {
			prefixSum[index][letter] = prefixSum[index - 1][letter];
		}
		prefixSum[index][str[index - 1] - 'a']++;
	}
	int numQuery;
	std::cin >> numQuery;
	while (numQuery--) {
		int left, right;
		std::cin >> left >> right;
		int count = 0;
		for (int letter = 0; letter < 26; letter++) {
			count += prefixSum[right][letter] - prefixSum[left - 1][letter] > 0;
		}
		std::cout << (count > 2 || str[right - 1] != str[left - 1] || left == right ? "Yes" : "No") << '\n';
	}
	return 0;
}