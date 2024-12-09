#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numNode;
	std::cin >> numNode;
	std::vector<std::vector<int>> adjacent(numNode);
	for (int edge = 1; edge < numNode; edge++) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		adjacent[u].emplace_back(v);
		adjacent[v].emplace_back(u);
	}
	int countOdd = 0, countEven = 0;
	std::function<void(int, int, int)> depthFirstSearch = [&](int currentNode, int previousNode, bool isOdd) {
		if (isOdd) {
			countOdd++;
		} else {
			countEven++;
		}
		for (const int &nextNode : adjacent[currentNode]) {
			if (nextNode != previousNode) {
				depthFirstSearch(nextNode, currentNode, !isOdd);
			}
		}
	};
	depthFirstSearch(0, -1, false);
	std::cout << 1ll * countOdd * countEven - (numNode - 1);
	return 0;
}