/*
practicing..
*/
#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCity, numRoad;
	std::cin >> numCity >> numRoad;
	std::vector<std::vector<int>> adjacent(numCity);
	for (int road = 0; road < numRoad; road++) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		adjacent[u].emplace_back(v);
		adjacent[v].emplace_back(u);
	}
	std::vector<std::array<int, 3>> result;
	std::vector<int> visited(numCity, false);
	std::function<bool(int, int)> depthFirstSearch = [&](int currentCity, int previousCity) {
		std::vector<int> neighbor;
		visited[currentCity] = true;
		for (const int &nextCity : adjacent[currentCity]) {
			if (nextCity != previousCity) {
				if (visited[nextCity]) {
					if (currentCity < nextCity) {
						neighbor.emplace_back(nextCity);
					}
				} else if (depthFirstSearch(nextCity, currentCity)) {
					neighbor.emplace_back(nextCity);
				}
			}
		}
		for (int index = 0; index < (int)neighbor.size() / 2; index++) {
			result.push_back({neighbor[2 * index], currentCity, neighbor[2 * index + 1]});
		}
		if ((int)neighbor.size() % 2 == 0) {
			return true;
		}
		if (previousCity != -1) {
			result.push_back({neighbor[(int)neighbor.size() - 1], currentCity, previousCity});
		}
		return false;
	};
	for (int city = 0; city < numCity; city++) {
		if (!visited[city]) {
			depthFirstSearch(city, -1);
		}
	}
	assert((int)result.size() <= numRoad / 2);
	std::cout << (int)result.size() << '\n';
	for (const auto [city1, city2, city3] : result) {
		std::cout << city1 + 1 << ' ' << city2 + 1 << ' ' << city3 + 1 << '\n';
	}
	return 0;
}