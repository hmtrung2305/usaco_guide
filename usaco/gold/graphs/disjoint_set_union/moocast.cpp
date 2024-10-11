#include <bits/stdc++.h>

struct Edge {
	int u, v, distance;
};

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
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	std::vector<std::pair<int, int>> positionCow(numCow);
	for (auto &[x, y] : positionCow) {
		std::cin >> x >> y;
	}
	std::vector<Edge> edges;
	for (int cow1 = 0; cow1 < numCow - 1; cow1++) {
		for (int cow2 = cow1 + 1; cow2 < numCow; cow2++) {
			int distanceX = positionCow[cow1].first - positionCow[cow2].first;
			int distanceY = positionCow[cow1].second - positionCow[cow2].second;
			edges.push_back({cow1, cow2, distanceX * distanceX + distanceY * distanceY});
		}
	}
	sort(edges.begin(), edges.end(), [](const Edge& edge1, const Edge& edge2) {
		return edge1.distance < edge2.distance;
	});
	int component = 0;
	int result = 0;
	DisjointSetUnion dsu(numCow);
	for (const auto &[u, v, distance] : edges) {
		if (dsu.unionNode(u, v)) {
			component--;
			result = distance;
			if (component == 1) {
				break;
			}
		}
	}
	std::cout << result;
	return 0;
}