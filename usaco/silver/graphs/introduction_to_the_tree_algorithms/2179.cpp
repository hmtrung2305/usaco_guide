#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numNode, numEdge;
	std::cin >> numNode >> numEdge;
	std::vector<std::vector<int>> adjacent(numNode);
	while (numEdge--) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		adjacent[u].emplace_back(v);
		adjacent[v].emplace_back(u);
	}
	std::vector<std::pair<int, int>> result;
	std::vector<int> timeNode(numNode);
	std::vector<int> beOdd(numNode, 0);
	int time = 0;
	std::function<void(int, int)> depthFirstSearch = [&](int currentNode, int previousNode) {
		time++;
		timeNode[currentNode] = time;
		for (const int &nextNode : adjacent[currentNode]) {
			if (nextNode != previousNode) {
				if (timeNode[nextNode] == 0) {
					depthFirstSearch(nextNode, currentNode);
					if (beOdd[nextNode]) {
						result.emplace_back(nextNode, currentNode);
						beOdd[nextNode] = 0;
					} else {
						result.emplace_back(currentNode, nextNode);
						beOdd[currentNode] ^= 1;
					}
				} else if (timeNode[currentNode] > timeNode[nextNode]) {
					result.emplace_back(currentNode, nextNode);
					beOdd[currentNode] ^= 1;
				}
			}
		}
	};
	for (int node = 0; node < numNode; node++) {
		if (timeNode[node] == 0) {
			depthFirstSearch(node, -1);
		}
	}
	if (accumulate(beOdd.begin(), beOdd.end(), 0) > 0) {
		std::cout << "IMPOSSIBLE";
		return 0;
	}
	for (const auto &[from, to] : result) {
		std::cout << from + 1 << ' ' << to + 1 << '\n';
	}
	return 0;
}