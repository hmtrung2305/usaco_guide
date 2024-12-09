#include <bits/stdc++.h>

int main() {
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numFarm, numCow;
	std::cin >> numFarm >> numCow;
	std::vector<std::vector<int>> adjacentS(numFarm), adjacentD(numFarm);
	while (numCow--) {
		int u, v;
		char type;
		std::cin >> type >> u >> v;
		u--; v--;
		if (type == 'S') {
			adjacentS[u].emplace_back(v);
			adjacentS[v].emplace_back(u);
		} else {
			adjacentD[u].emplace_back(v);
			adjacentD[v].emplace_back(u);
		}
	}
	std::vector<int> colorFarm(numFarm, -1);
	bool satisfyCondition = true;
	std::function<void(int, int)> depthFirstSearch = [&](int currentFarm, int color) {
		colorFarm[currentFarm] = color;
		for (const int &nextFarm : adjacentS[currentFarm]) {
			if (colorFarm[nextFarm] == (1 ^ color)) {
				satisfyCondition = false;
			}
			if (colorFarm[nextFarm] == -1) {
				depthFirstSearch(nextFarm, color);
			}
		}
		for (const int &nextFarm : adjacentD[currentFarm]) {
			if (colorFarm[nextFarm] == color) {
				satisfyCondition = false;
			}
			if (colorFarm[nextFarm] == -1) {
				depthFirstSearch(nextFarm, color ^ 1);
			}
		}
	};
	int component = 0;
	for (int farm = 0; farm < numFarm; farm++) {
		if (colorFarm[farm] == -1) {
			component++;
			depthFirstSearch(farm, 0);
		}
	}
	if (!satisfyCondition) {
		std::cout << satisfyCondition;
	} else {
		std::cout << 1;
		for (int index = 0; index < component; index++) {
			std::cout << 0;
		}
	}
	return 0;
}