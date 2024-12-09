#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int numVertex, numEdge;
		std::cin >> numVertex >> numEdge;
		std::vector<std::vector<int>> adjacent(numVertex);
		while (numEdge--) {
			int u, v;
			std::cin >> u >> v;
			u--; v--;
			adjacent[u].emplace_back(v);
			adjacent[v].emplace_back(u);
		}
		std::vector<int> vertexOdd, vertexEven;
		std::vector<bool> visitedVertex(numVertex);
		std::function<void(int, int)> depthFirstSearch = [&](int currentVertex, int distance) {
			visitedVertex[currentVertex] = true;
			if (distance & 1) {
				vertexOdd.emplace_back(currentVertex);
			} else {
				vertexEven.emplace_back(currentVertex);
			}
			for (const int &nextVertex : adjacent[currentVertex]) {
				if (!visitedVertex[nextVertex]) {
					depthFirstSearch(nextVertex, distance + 1);
				}
			}
		};
		depthFirstSearch(0, 0);
		if ((int)vertexOdd.size() < (int)vertexEven.size()) {
			std::cout << (int)vertexOdd.size() << '\n';
			for (const int &vertex : vertexOdd) {
				std::cout << vertex + 1 << ' ';
			}
		} else {
			std::cout << (int)vertexEven.size() << '\n';
			for (const int &vertex : vertexEven) {
				std::cout << vertex + 1 << ' ';
			}
		}
		std::cout << '\n';
	}
	return 0;
}