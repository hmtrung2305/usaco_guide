#include <bits/stdc++.h>

int main() {
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numBarn, numConnection;
	std::cin >> numBarn >> numConnection;
	std::vector<std::vector<int>> adjacent(numBarn);
	while (numConnection--) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		adjacent[u].emplace_back(v);
		adjacent[v].emplace_back(u);
	}
	std::queue<int> queueBarn;
	std::vector<int> isBarnClosed(numBarn, false);
	std::cout << "YES" << '\n';
	for (int numClosed = 1; numClosed <= numBarn; numClosed++) {
		int barnClosed;
		std::cin >> barnClosed;
		barnClosed--;
		if (numClosed == numBarn) {
			return 0;
		}
		isBarnClosed[barnClosed] = true;
		std::vector<bool> visitedBarn(numBarn, false);
		for (int barn = 0; barn < numBarn; barn++) {
			if (!isBarnClosed[barn]) {
				visitedBarn[barn] = true;
				queueBarn.emplace(barn);
				while (!queueBarn.empty()) {
					int currentBarn = queueBarn.front();
					queueBarn.pop();
					for (const int &nextBarn : adjacent[currentBarn]) {
						if (!visitedBarn[nextBarn] && !isBarnClosed[nextBarn]) {
							visitedBarn[nextBarn] = true;
							queueBarn.emplace(nextBarn);
						}
					}
				}
				break;
			}
		}
		std::cout << (count(visitedBarn.begin(), visitedBarn.end(), true) == numBarn - numClosed ? "YES" : "NO") << '\n';
	}
	return 0;
}