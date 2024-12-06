#include <bits/stdc++.h>

struct DisjointSetUnion {
	std::vector<int> parentNode;
	std::vector<int> sizeNode;

	DisjointSetUnion(int numNode) {
		parentNode.resize(numNode);
		iota(parentNode.begin(), parentNode.end(), 0);
		sizeNode.assign(numNode, 0);
	}

	int findNode(int node) {
		return (node == parentNode[node] ? node : parentNode[node] = findNode(parentNode[node]));
	}

	bool unionNode(int node1, int node2) {
		node1 = findNode(node1);
		node2 = findNode(node2);
		if (node1 == node2) {
			return false;
		}
		if (sizeNode[node1] > sizeNode[node2]) {
			std::swap(node1, node2);
		}
		parentNode[node1] = node2;
		sizeNode[node2] += sizeNode[node1];
		return true;
	}
};

int main() {
	freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow, numWormhole;
	std::cin >> numCow >> numWormhole;
	std::vector<int> positionCow(numCow);
	for (int index = 0; index < numCow; index++) {
		std::cin >> positionCow[index];
		positionCow[index]--;
	}
	if (is_sorted(positionCow.begin(), positionCow.end())) {
		std::cout << -1;
		return 0;
	}
	DisjointSetUnion dsu(numCow);
	std::vector<std::array<int, 3>> edges;
	for (int index = 0; index < numWormhole; index++) {
		int a, b, weight;
		std::cin >> a >> b >> weight;
		a--; b--;
		edges.push_back({weight, a, b});
	}
	sort(edges.begin(), edges.end(), std::greater<std::array<int, 3>>());
	int result = 1e9;
	for (auto [weight, a, b] : edges) {
		if ((positionCow[a] != a || positionCow[b] != b) && dsu.unionNode(a, b)) {
			result = std::min(result, weight);
		}
	}
	std::cout << result;
	return 0;
}