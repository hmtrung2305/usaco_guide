#include <bits/stdc++.h>

void depthFirstSearch(const std::vector<std::vector<int>>& adjacent, std::vector<int>& distanceNode, int currentNode, int previousNode) {
	for (int nextNode : adjacent[currentNode]) {
		if (nextNode != previousNode) {
			distanceNode[nextNode] = distanceNode[currentNode] + 1;
			depthFirstSearch(adjacent, distanceNode, nextNode, currentNode);
		}
	}
}

int findDiameter(const std::vector<std::vector<int>>& adjacent) {
	int numNode = (int)adjacent.size();
	std::vector<int> distanceNode(numNode);
	depthFirstSearch(adjacent, distanceNode, 0, -1);
	int maxDistance = -1, furthestNode = -1;
	for (int node = 0; node < numNode; node++) {
		if (maxDistance < distanceNode[node]) {
			maxDistance = distanceNode[node];
			furthestNode = node;
		}
	}
	distanceNode.assign(numNode, 0);
	depthFirstSearch(adjacent, distanceNode, furthestNode, -1);
	return *max_element(distanceNode.begin(), distanceNode.end());
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numNodeTree1;
	std::cin >> numNodeTree1;
	std::vector<std::vector<int>> adjacentTree1(numNodeTree1);
	for (int edge = 0; edge < numNodeTree1 - 1; edge++) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		adjacentTree1[u].emplace_back(v);
		adjacentTree1[v].emplace_back(u);
	}
	int numNodeTree2;
	std::cin >> numNodeTree2;
	std::vector<std::vector<int>> adjacentTree2(numNodeTree2);
	for (int edge = 0; edge < numNodeTree2 - 1; edge++) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		adjacentTree2[u].emplace_back(v);
		adjacentTree2[v].emplace_back(u);
	}
	int diameterTree1 = findDiameter(adjacentTree1);
	int diameterTree2 = findDiameter(adjacentTree2);
	std::cout << std::max({diameterTree1, diameterTree2, (diameterTree1 + 1) / 2 + (diameterTree2 + 1) / 2 + 1});
	return 0;
}