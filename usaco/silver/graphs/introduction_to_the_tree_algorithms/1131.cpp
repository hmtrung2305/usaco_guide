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
	std::vector<int> distanceNode(numNode);
	std::function<void(int, int)> depthFirstSearch = [&](int currentNode, int previousNode) {
		for (int nextNode : adjacent[currentNode]) {
			if (nextNode != previousNode) {
				distanceNode[nextNode] = distanceNode[currentNode] + 1;
				depthFirstSearch(nextNode, currentNode);
			}
		}
	};
	depthFirstSearch(0, -1);
	int maxDistance = -1, furthestNode = -1;
	for (int node = 0; node < numNode; node++) {
		if (distanceNode[node] > maxDistance) {
			maxDistance = distanceNode[node];
			furthestNode = node;
		}
	}
	distanceNode.assign(numNode, 0);
	depthFirstSearch(furthestNode, -1);
	std::cout << *std::max_element(distanceNode.begin(), distanceNode.end());
	return 0;
}