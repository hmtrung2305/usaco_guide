#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numBall;
	std::cin >> numBall;
	std::vector<std::vector<int>> adjacent(numBall);
	for (int index = 0; index < numBall; index++) {
		int p;
		std::cin >> p;
		p--;
		adjacent[p].emplace_back(index);
		adjacent[index].emplace_back(p);
	}
	std::vector<bool> visited(numBall);
	std::function<void(int)> depthFirstSearch = [&](int current) {
		visited[current] = true;
		for (int next : adjacent[current]) {
			if (!visited[next]) {
				depthFirstSearch(next);
			}
		}
	};
	int tree = 0;
	for (int index = 0; index < numBall; index++) {
		if (!visited[index]) {
			tree++;
			depthFirstSearch(index);
		}
	}
	std::cout << tree;
	return 0;
}