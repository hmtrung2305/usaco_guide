#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numNode;
	std::cin >> numNode;
	std::vector<std::vector<int>> adjacent(numNode);
	for (int edge = 0; edge < numNode - 1; edge++) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		adjacent[u].emplace_back(v);
		adjacent[v].emplace_back(u);
	}
	std::vector<std::array<int, 2>> distanceNode(numNode);
	std::function<int(int, int, int, int)> depthFirstSearch = [&](int currentNode, int previousNode, int distance, int option) {
		distanceNode[currentNode][option] = distance;
		int furthestNode = -1;
		for (int nextNode : adjacent[currentNode]) {
			if (nextNode != previousNode) {
				int furthestNextNode = depthFirstSearch(nextNode, currentNode, distance + 1, option);
				if (furthestNode == -1 || distanceNode[furthestNextNode][option] > distanceNode[furthestNode][option]) {
					furthestNode = furthestNextNode;
				}
			}
		}
		return furthestNode == -1 ? currentNode : furthestNode;
	};
	int furthestNodeA = depthFirstSearch(0, -1, 0, 0);
	int furthestNodeB = depthFirstSearch(furthestNodeA, -1, 0, 0);
	depthFirstSearch(furthestNodeB, -1, 0, 1);
	for (int node = 0; node < numNode; node++) {
		std::cout << std::max(distanceNode[node][0], distanceNode[node][1]) << ' ';
	}
	return 0;
}