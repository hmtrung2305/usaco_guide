#include <bits/stdc++.h>

struct DisjointSetUnion {
	std::vector<int> parrentNode;
	std::vector<int> sizeNode;

	DisjointSetUnion(int numNode) {
		parrentNode.resize(numNode);
		iota(parrentNode.begin(), parrentNode.end(), 0);
		sizeNode.assign(numNode, 1);
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
		if (sizeNode[node1] > sizeNode[node2]) {
			std::swap(node1, node2);
		}
		parrentNode[node1] = node2;
		sizeNode[node2] += sizeNode[node1];
		return true;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCity, numRoad;
	std::cin >> numCity >> numRoad;
	DisjointSetUnion dsu(numCity);
	while (numRoad--) {
		int city1, city2;
		std::cin >> city1 >> city2;
		city1--; city2--;
		dsu.unionNode(city1, city2);
	}
	std::vector<int> independentCity;
	for (int city = 0; city < numCity; city++) {
		if (dsu.findNode(city) == city) {
			independentCity.emplace_back(city);
		}
	}
	std::cout << (int)independentCity.size() - 1 << '\n';
	for (int index = 1; index < (int)independentCity.size(); index++) {
		std::cout << independentCity[index - 1] + 1 << ' ' << independentCity[index] + 1 << '\n';
	}
	return 0;
}