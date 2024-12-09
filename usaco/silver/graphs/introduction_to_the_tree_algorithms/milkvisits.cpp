#include <bits/stdc++.h>

int main() {
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numFarm, numQuery;
	std::cin >> numFarm >> numQuery;
	std::string typeFarm;
	std::cin >> typeFarm;
	std::vector<std::vector<int>> adjacent(numFarm);
	for (int road = 1; road < numFarm; road++) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		adjacent[u].emplace_back(v);
		adjacent[v].emplace_back(u);
	}
	std::vector<int> typeComponent(numFarm, -1);
	int countComponent = 0;
	std::function<void(int, int)> depthFirstSearch = [&](int currentFarm, int previousFarm) {
		typeComponent[currentFarm] = countComponent;
		for (int nextFarm : adjacent[currentFarm]) {
			if (nextFarm != previousFarm && typeFarm[currentFarm] == typeFarm[nextFarm]) {
				depthFirstSearch(nextFarm, currentFarm);
			}
		}
	};
	for (int farm = 0; farm < numFarm; farm++) {
		if (typeComponent[farm] == -1) {
			depthFirstSearch(farm, -1);
			countComponent++;
		}
	}
	while (numQuery--) {
		int u, v;
		char type;
		std::cin >> u >> v >> type;
		u--; v--;
		if (typeComponent[u] == typeComponent[v]) {
			std::cout << (typeFarm[u] == type ? 1 : 0);
		} else {
			std::cout << 1;
		}
	}
	return 0;
}