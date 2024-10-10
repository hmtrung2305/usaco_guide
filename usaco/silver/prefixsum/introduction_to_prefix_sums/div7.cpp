#include <bits/stdc++.h>

int main() {
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	std::vector<int> firstPosition(7);
	int currentSum = 0;
	int result = 0;
	for (int index = 1; index <= numCow; index++) {
		int idCow;
		std::cin >> idCow;
		currentSum = (currentSum + idCow) % 7;
		if (firstPosition[currentSum] == 0) {
			firstPosition[currentSum] = index;
		}
		result = std::max(result, index - firstPosition[currentSum]);
	}
	std::cout << result;
	return 0;
}