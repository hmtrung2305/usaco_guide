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
	std::vector<int> distance(numNode, 1e9);
	int result = 1e9;
	for (int node = 0; node < numNode; node++) {
		distance.assign(numNode, 1e9);
		std::queue<int> queueNode;
		queueNode.emplace(node);
		distance[node] = 0;
		while (!queueNode.empty()) {
			int currentNode = queueNode.front();
			queueNode.pop();
			for (int nextNode : adjacent[currentNode]) {
				if (distance[nextNode] == 1e9) {
					distance[nextNode] = distance[currentNode] + 1;
					queueNode.emplace(nextNode);
				} else if (distance[nextNode] >= distance[currentNode]) {
					result = std::min(result, distance[nextNode] + distance[currentNode] + 1);
				}
			}
		}
	}
	std::cout << (result == 1e9 ? -1 : result);
	return 0;
}