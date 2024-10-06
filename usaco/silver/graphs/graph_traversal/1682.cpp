#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCity, numFlight;
	std::cin >> numCity >> numFlight;
	std::vector<std::vector<std::vector<int>>> adjacent(2, std::vector<std::vector<int>>(numCity));
	while (numFlight--) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		adjacent[0][u].emplace_back(v);
		adjacent[1][v].emplace_back(u);
	}
	std::vector<bool> visitedCity(numCity, false);
	std::function<void(int, int)> depthFirstSearch = [&](int current, int type) {
		visitedCity[current] = true;
		for (int next : adjacent[type][current]) {
			if (!visitedCity[next]) {
				depthFirstSearch(next, type);
			}
		}
	};
	depthFirstSearch(0, 0);
	for (int city = 0; city < numCity; city++) {
		if (!visitedCity[city]) {
			std::cout << "NO\n" << 1 << ' ' << city + 1;
			return 0;
		}
	}
	visitedCity.assign(numCity, false);
	depthFirstSearch(0, 1);
	for (int city = 0; city < numCity; city++) {
		if (!visitedCity[city]) {
			std::cout << "NO\n" << city + 1 << ' ' << 1;
			return 0;
		}
	}
	std::cout << "YES";
	return 0;
}