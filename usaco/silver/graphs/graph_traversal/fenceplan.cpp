#include <bits/stdc++.h>

int main() {
	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow, numConnection;
	std::cin >> numCow >> numConnection;
	std::vector<std::pair<int, int>> cows(numCow);
	for (int index = 0; index < numCow; index++) {
		std::cin >> cows[index].first >> cows[index].second;
	}
	std::vector<std::vector<int>> adjacent(numCow);
	while (numConnection--) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		adjacent[u].emplace_back(v);
		adjacent[v].emplace_back(u);
	}
	std::vector<bool> visitedCow(numCow, false);
	std::queue<int> queueCow;
	int minPerimeter = 1e9;
	for (int index = 0; index < numCow; index++) {
		if (!visitedCow[index]) {
			visitedCow[index] = true;
			int minX = cows[index].first, maxX = cows[index].first;
			int minY = cows[index].second, maxY = cows[index].second;
			queueCow.emplace(index);
			while (!queueCow.empty()) {
				int currentCow = queueCow.front();
				queueCow.pop();
				for (const int &nextCow : adjacent[currentCow]) {
					if (!visitedCow[nextCow]) {
						visitedCow[nextCow] = true;
						minX = std::min(minX, cows[nextCow].first);
						maxX = std::max(maxX, cows[nextCow].first);
						minY = std::min(minY, cows[nextCow].second);
						maxY = std::max(maxY, cows[nextCow].second);
						queueCow.emplace(nextCow);
					}
				}
			}
			minPerimeter = std::min(minPerimeter, 2 * (maxX - minX + maxY - minY));
		}
	}
	std::cout << (minPerimeter == 1e9 ? 0 : minPerimeter);
	return 0;
}