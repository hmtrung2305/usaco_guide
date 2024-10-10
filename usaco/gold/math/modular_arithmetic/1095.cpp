#include <bits/stdc++.h>

const int MODULO = 1e9 + 7;

int power(int base, int exponent) {
	int result = 1;
	while (exponent > 0) {
		if (exponent & 1) {
			result = (1ll * result * base) % MODULO;
		}
		base = (1ll * base * base) % MODULO;
		exponent >>= 1;
	}
	return result;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int base, exponent;
		std::cin >> base >> exponent;
		std::cout << power(base, exponent) << '\n';
	}
	return 0;
}