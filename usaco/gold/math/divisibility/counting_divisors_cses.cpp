#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numQuery;
	std::cin >> numQuery;
	while (numQuery--) {
		int num;
		std::cin >> num;
		int result = 0;
		for (int divisor = 1; divisor * divisor <= num; divisor++) {
			if (num % divisor == 0) {
				result += (divisor == num / divisor ? 1 : 2);
			}
		}
		std::cout << result << '\n';
	}
	return 0;
}