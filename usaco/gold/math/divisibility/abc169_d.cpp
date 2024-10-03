#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	long long num;
	std::cin >> num;
	int result = 0;
	for (int divisor = 2; 1ll * divisor * divisor <= num; divisor++) {
		if (num % divisor == 0) {
			num /= divisor;
			result++;
			std::cout << divisor << ' ' << num << '\n';
		}
	}
	std::cout << num << ' ';
	std::cout << result + (num > 1) << '\n';
	return 0;
}