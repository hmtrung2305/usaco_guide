#include <bits/stdc++.h>

const int MODULO = 1e9 + 7;
const int CITY = 20;

int count[1 << CITY][CITY];
bool visited[1 << CITY][CITY];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCity, numFlight;
	std::cin >> numCity >> numFlight;
	std::vector<std::vector<int>> adjacent(numCity);
	while (numFlight--) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		adjacent[u].emplace_back(v);
	}
	std::queue<std::pair<int, int>> queueCity;
	queueCity.emplace(1, 0);
	count[1][0] = 1;
	visited[1][0] = true;
	while (!queueCity.empty()) {
		auto [bitmask, currentCity] = queueCity.front();
		queueCity.pop();
		if (currentCity == numCity - 1) {
			continue;
		}
		for (int nextCity : adjacent[currentCity]) {
			if ((bitmask & (1 << nextCity)) > 0) {
				continue;
			}
			count[bitmask | (1 << nextCity)][nextCity] = (count[bitmask | (1 << nextCity)][nextCity] + count[bitmask][currentCity]) % MODULO;
			if (visited[bitmask | (1 << nextCity)][nextCity]) {
				continue;
			}
			queueCity.emplace(bitmask | (1 << nextCity), nextCity);
			visited[bitmask | (1 << nextCity)][nextCity] = true;
		}
	}
	std::cout << count[(1 << numCity) - 1][numCity - 1];
	return 0;
}