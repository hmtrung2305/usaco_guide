#include <bits/stdc++.h>

struct DisjointSetUnion {
	int numNode;
	std::vector<int> parrentNode;
	std::vector<int> rankNode;

	DisjointSetUnion(int inputNode) : numNode(inputNode) {
		parrentNode.resize(numNode);
		iota(parrentNode.begin(), parrentNode.end(), 0);
		rankNode.assign(numNode, 1);
	}

	int findNode(int node) {
		return (node == parrentNode[node] ? node : parrentNode[node] = findNode(parrentNode[node]));
	}

	bool unionNode(int node1, int node2) {
		node1 = findNode(node1);
		node2 = findNode(node2);
		if (node1 == node2) {
			return false;
		}
		if (rankNode[node1] > rankNode[node2]) {
			std::swap(node1, node2);
		}
		rankNode[node2] += rankNode[node1];
		parrentNode[node1] = node2;
		return true;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numVertex, numQuery;
	std::cin >> numVertex >> numQuery;
	DisjointSetUnion dsu(numVertex);
	while (numQuery--) {
		int operation, u, v;
		std::cin >> operation >> u >> v;
		if (operation == 0) {
			dsu.unionNode(u, v);
		} else {
			std::cout << (dsu.findNode(u) == dsu.findNode(v)) << '\n';
		}
	}
	return 0;
}