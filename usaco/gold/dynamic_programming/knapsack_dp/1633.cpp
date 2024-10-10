#include <bits/stdc++.h>

const int MODULO = 1e9 + 7;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int sumDice;
	std::cin >> sumDice;
	std::vector<int> countWay(sumDice + 1);
	countWay[0] = 1;
	for (int sum = 1; sum <= sumDice; sum++) {
		for (int dice = 1; dice <= std::min(sum, 6); dice++) {
			countWay[sum] = (countWay[sum] + countWay[sum - dice]) % MODULO;
		}
	}
	std::cout << countWay[sumDice];
	return 0;
}