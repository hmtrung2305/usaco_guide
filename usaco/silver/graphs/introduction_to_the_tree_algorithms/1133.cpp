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
	std::vector<long long> result(numNode);
	std::vector<long long> sizeSubtree(numNode);
	std::function<void(int, int, int)> findSubtree = [&](int currentNode, int previousNode, int depth) {
		result[0] += depth;
		sizeSubtree[currentNode] = 1;
		for (const int &nextNode : adjacent[currentNode]) {
			if (nextNode != previousNode) {
				findSubtree(nextNode, currentNode, depth + 1);
				sizeSubtree[currentNode] += sizeSubtree[nextNode];
			}
		}
	};
	findSubtree(0, -1, 0);
	std::function<void(int, int)> findAllNode = [&](int currentNode, int previousNode) {
		for (const int &nextNode : adjacent[currentNode]) {
			if (nextNode != previousNode) {
				result[nextNode] = result[currentNode] + numNode - 2 * sizeSubtree[nextNode];
				findAllNode(nextNode, currentNode);
			}
		}
	};
	findAllNode(0, -1);
	for (const long long &distance : result) {
		std::cout << distance << ' ';
	}
	return 0;
}