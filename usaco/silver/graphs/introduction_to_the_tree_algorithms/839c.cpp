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
	std::function<double(int, int)> depthFirstSearch = [&](int currentNode, int previousNode) {
		double sum = 0;
		for (int nextNode : adjacent[currentNode]) {
			if (nextNode != previousNode) {
				sum += depthFirstSearch(nextNode, currentNode) + 1;
			}
		}
		return sum > 0 ? sum / ((int)adjacent[currentNode].size() - (previousNode != -1)) : 0;
	};
	std::cout << std::fixed << std::setprecision(6) << depthFirstSearch(0, -1);
	return 0;
}