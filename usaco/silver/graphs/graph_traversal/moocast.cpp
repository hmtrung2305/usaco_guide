#include <bits/stdc++.h>

int main() {
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	std::vector<std::array<int, 3>> cows(numCow);
	for (auto &[x, y, power] : cows) {
		std::cin >> x >> y >> power;
	}
	std::vector<std::vector<int>> adjacent(numCow);
	for (int cow1 = 0; cow1 < numCow; cow1++) {
		for (int cow2 = 0; cow2 < numCow; cow2++) {
			auto [x1, y1, power1] = cows[cow1];
			auto [x2, y2, power2] = cows[cow2];
			if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= power1 * power1) {
				adjacent[cow1].emplace_back(cow2);
			}
		}
	}
	int result = 0;
	std::queue<int> queueCow;
	for (int cow = 0; cow < numCow; cow++) {
		queueCow.emplace(cow);
		std::vector<int> visited(numCow, false);
		visited[cow] = true;
		int reach = 1;
		while (!queueCow.empty()) {
			int currentCow = queueCow.front();
			queueCow.pop();
			for (int nextCow : adjacent[currentCow]) {
				if (!visited[nextCow]) {
					reach++;
					visited[nextCow] = true;
					queueCow.emplace(nextCow);
				}
			}
		}
		result = std::max(result, reach);
	}
	std::cout << result;
	return 0;
}