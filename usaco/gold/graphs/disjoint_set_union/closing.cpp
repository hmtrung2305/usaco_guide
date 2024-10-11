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
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numBarn, numConnect;
	std::cin >> numBarn >> numConnect;
	std::vector<std::vector<int>> adjacent(numBarn);
	while (numConnect--) {
		int barn1, barn2;
		std::cin >> barn1 >> barn2;
		barn1--; barn2--;
		adjacent[barn1].emplace_back(barn2);
		adjacent[barn2].emplace_back(barn1);
	}
	std::vector<int> barnClose(numBarn);
	for (int index = 0; index < numBarn; index++) {
		std::cin >> barnClose[index];
		barnClose[index]--;
	}
	reverse(barnClose.begin(), barnClose.end());
	DisjointSetUnion dsu(numBarn);
	std::vector<bool> result{1};
	std::vector<bool> opened(numBarn);
	opened[barnClose[0]] = true;
	for (int index = 1; index < numBarn; index++) {
		opened[barnClose[index]] = true;
		for (int nextBarn : adjacent[barnClose[index]]) {
			if (opened[nextBarn]) {
				dsu.unionNode(barnClose[index], nextBarn);
			}
		}
		result.emplace_back(dsu.getSize(barnClose[index]) == index + 1 ? true : false);
	}
	reverse(result.begin(), result.end());
	for (bool status : result) {
		std::cout << (status == true ? "YES" : "NO") << '\n';
	}
	return 0;
}