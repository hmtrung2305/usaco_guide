#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::string str;
	std::cin >> str;
	sort(str.begin(), str.end());
	std::vector<std::string> result;
	do {
		result.emplace_back(str);
	} while (next_permutation(str.begin(), str.end()));
	std::cout << (int)result.size() << '\n';
	for (const std::string &s : result) {
		std::cout << s << '\n';
	}
	return 0;
}