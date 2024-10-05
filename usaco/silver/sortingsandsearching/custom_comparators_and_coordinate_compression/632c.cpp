#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthStr;
	std::cin >> lengthStr;
	std::vector<std::string> strings(lengthStr);
	for (std::string &str : strings) {
		std::cin >> str;
	}
	sort(strings.begin(), strings.end(), [](std::string str1, std::string str2) {
		return str1 + str2 < str2 + str1;
	});
	for (std::string str : strings) {
		std::cout << str;
	}
	return 0;
}