#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numFarm;
	std::cin >> numFarm;
	std::vector<std::vector<int>> adjacent(numFarm);
	for (int road = 0; road < numFarm - 1; road++) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		adjacent[u].emplace_back(v);
		adjacent[v].emplace_back(u);
	}
	std::function<int(int, int)> depthFirstSearch = [&](int currentFarm, int previousFarm) {
		int day = 0;
		int cow = (int)adjacent[currentFarm].size();
		if (previousFarm == -1) {
			cow++;
		}
		int currentCow = 1;
		while (currentCow < cow) {
			day++;
			currentCow <<= 1;
		}
		for (int nextFarm : adjacent[currentFarm]) {
			if (nextFarm != previousFarm) {
				day += depthFirstSearch(nextFarm, currentFarm) + 1;
			}
		}
		return day;
	};
	std::cout << depthFirstSearch(0, -1);
	return 0;
}