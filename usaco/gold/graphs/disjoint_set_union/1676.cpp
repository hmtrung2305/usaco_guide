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

	int getSize(int node) {
		return rankNode[findNode(node)];
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
	int numCity, numEdge;
	std::cin >> numCity >> numEdge;
	DisjointSetUnion dsu(numCity);
	int component = numCity, maxSize = 1;
	while (numEdge--) {
		int city1, city2;
		std::cin >> city1 >> city2;
		city1--; city2--;
		if (dsu.unionNode(city1, city2)) {
			component--;
		}
		maxSize = std::max(maxSize, dsu.getSize(city1));
		std::cout << component << ' ' << maxSize << '\n';
	}
	return 0;
}