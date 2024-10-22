#include <bits/stdc++.h>

class Tree {
private:
	const int root = 0;

	const std::vector<std::vector<int>> &adjacent;
	const int log2Distance;
	std::vector<int> parent;
	std::vector<std::vector<int>> power2Ends;
	std::vector<int> depthNode;

	void process(int currentNode, int previousNode) {
		depthNode[currentNode] = depthNode[previousNode] + 1;
		for (const int &nextNode : adjacent[currentNode]) {
			if (nextNode != previousNode) {
				process(nextNode, currentNode);
				parent[nextNode] = currentNode;
			}
		}
	}

public:
	Tree(const std::vector<std::vector<int>> &inputAdjacent) :
		adjacent(inputAdjacent), 
		log2Distance(std::ceil(std::log2((int)adjacent.size()))), 
		parent((int)adjacent.size()),
		power2Ends((int)parent.size(), std::vector<int>(log2Distance + 1)),
		depthNode((int)adjacent.size()) {
		parent[root] = -1;
		depthNode[root] = -1;
		process(root, -1);

		for (int node = 0; node < (int)adjacent.size(); node++) {
			power2Ends[node][0] = parent[node];
		}
		for (int log2 = 1; log2 <= log2Distance; log2++) {
			for (int node = 0; node < (int)parent.size(); node++) {
				int halfWay = power2Ends[node][log2 - 1];
				if (halfWay == -1) {
					power2Ends[node][log2] = -1;
				} else {
					power2Ends[node][log2] = power2Ends[halfWay][log2 - 1];
				}
			}
		}
	}

	int kthParent(int node, int k) {
		if (k > (int)parent.size()) {
			return -1;
		}
		int currentNode = node;
		for (int power = 0; power <= log2Distance; power++) {
			if ((k & (1 << power)) != 0) {
				currentNode = power2Ends[currentNode][power];
				if (currentNode == -1) {
					break;
				}
			}
		}
		return currentNode;
	}

	int lowestCommonAncestor(int node1, int node2) {
		if (depthNode[node1] < depthNode[node2]) {
			std::swap(node1, node2);
		}
		node1 = kthParent(node1, depthNode[node1] - depthNode[node2]);
		if (node1 == node2) {
			return node1;
		}
		for (int log2 = log2Distance; log2 >= 0; log2--) {
			if (power2Ends[node1][log2] != power2Ends[node2][log2]) {
				node1 = power2Ends[node1][log2];
				node2 = power2Ends[node2][log2];
			}
		}
		return power2Ends[node1][0];
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numEmployee, numQuery;
	std::cin >> numEmployee >> numQuery;
	std::vector<std::vector<int>> adjacent(numEmployee);
	for (int employee = 1; employee < numEmployee; employee++) {
		int boss;
		std::cin >> boss;
		boss--;
		adjacent[boss].emplace_back(employee);
		adjacent[employee].emplace_back(boss);
	}
	Tree tree(adjacent);
	while (numQuery--) {
		int employee1, employee2;
		std::cin >> employee1 >> employee2;
		employee1--; employee2--;
		std::cout << tree.lowestCommonAncestor(employee1, employee2) + 1 << '\n';
	}
	return 0;
}