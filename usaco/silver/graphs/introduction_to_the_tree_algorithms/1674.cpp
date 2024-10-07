#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numEmployee;
	std::cin >> numEmployee;
	std::vector<std::vector<int>> adjacent(numEmployee);
	for (int index = 1; index < numEmployee; index++) {
		int boss;
		std::cin >> boss;
		boss--;
		adjacent[boss].emplace_back(index);
		adjacent[index].emplace_back(boss);
	}
	std::vector<int> totalSub(numEmployee);
	std::function<void(int, int)> depthfirstSearch = [&](int current, int previous) {
		totalSub[current] = 1;
		for (int next : adjacent[current]) {
			if (previous != next) {
				depthfirstSearch(next, current);
				totalSub[current] += totalSub[next];
			}
		}
	};
	depthfirstSearch(0, -1);
	for (int index = 0; index < numEmployee; index++) {
		std::cout << totalSub[index] - 1 << ' ';
	}
	return 0;
}