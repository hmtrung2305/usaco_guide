#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::string str;
	std::cin >> str;
	std::vector<int> count(2019);
	count[0] = 1;
	int num = 0, pow = 1;
	for (int index = (int)str.size() - 1; index >= 0; index--) {
		num = (num + pow * (str[index] - '0')) % 2019;
		count[num]++;
		pow = pow * 10 % 2019;
	}
	long long result = 0;
	for (int index = 0; index < 2019; index++) {
		result += 1ll * count[index] * (count[index] - 1) / 2;
	}
	std::cout << result;
	return 0;
}