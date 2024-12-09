#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numPeople, numPair;
	while (std::cin >> numPeople >> numPair && numPeople != 0) {
		std::vector<std::vector<int>> isAdjacent(numPeople, std::vector<int>(numPeople));
		std::vector<std::pair<int, int>> edges;
		while (numPair--) {
			int u, v;
			std::cin >> u >> v;
			isAdjacent[u][v] = true;
			isAdjacent[v][u] = true;
			edges.emplace_back(u, v);
		}
		std::vector<bool> visited;
		std::function<void(int)> depthFirstSearch = [&](int currentPeople) {
			visited[currentPeople] = true;
			for (int people = 0; people < numPeople; people++) {
				if (!visited[people] && isAdjacent[currentPeople][people]) {
					depthFirstSearch(people);
				}
			}
		};
		bool canConnect = true;
		for (const auto &[u, v] : edges) {
			visited.assign(numPeople, false);
			isAdjacent[u][v] = false;
			isAdjacent[v][u] = false;
			depthFirstSearch(0);
			for (int people = 0; people < numPeople; people++) {
				if (!visited[people]) {
					canConnect = false;
					break;
				}
			}
			isAdjacent[u][v] = true;
			isAdjacent[v][u] = true;
			if (!canConnect) {
				break;
			}
		}
		std::cout << (canConnect ? "No" : "Yes") << '\n';
	}
	return 0;
}