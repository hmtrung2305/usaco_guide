/*
practicing..
*/
#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int numPeople;
		std::cin >> numPeople;
		std::vector<std::vector<int>> adjacent(numPeople);
		for (int people = 0; people < numPeople; people++) {
			int u;
			std::cin >> u;
			u--;
			adjacent[u].emplace_back(people);
			adjacent[people].emplace_back(u);
		}
		for (int people = 0; people < numPeople; people++) {
			sort(adjacent[people].begin(), adjacent[people].end());
			adjacent[people].erase(unique(adjacent[people].begin(), adjacent[people].end()), adjacent[people].end());
		}
		std::vector<int> visited(numPeople, false);
		std::function<void(int)> depthFirstSearch = [&](int currentPeople) {
			visited[currentPeople] = true;
			for (const int &nextPeople : adjacent[currentPeople]) {
				if (!visited[nextPeople]) {
					depthFirstSearch(nextPeople);
				}
			}
		};
		int countSmallComponent = 0;
		for (int people = 0; people < numPeople; people++) {
			if (!visited[people] && (int)adjacent[people].size() == 1) {
				countSmallComponent++;
				depthFirstSearch(people);
			}
		}
		int countLargeComponent = 0;
		for (int people = 0; people < numPeople; people++) {
			if (!visited[people]) {
				countLargeComponent++;
				depthFirstSearch(people);
			}
		}
		std::cout << countLargeComponent + (countSmallComponent > 0) << ' ' << countSmallComponent + countLargeComponent << '\n';
	}
	return 0;
}