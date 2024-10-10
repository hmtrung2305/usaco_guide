#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numComputer, numConnection;
	std::cin >> numComputer >> numConnection;
	std::vector<std::vector<int>> adjacent(numComputer);
	while (numConnection--) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		adjacent[u].emplace_back(v);
		adjacent[v].emplace_back(u);
	}
	std::vector<int> distace(numComputer, -1), tracePath(numComputer, -1);
	std::queue<int> queueComputer;
	queueComputer.emplace(0);
	distace[0] = 0;
	while (!queueComputer.empty()) {
		int currentComputer = queueComputer.front();
		queueComputer.pop();
		for (int nextComputer : adjacent[currentComputer]) {
			if (distace[nextComputer] == -1) {
				distace[nextComputer] = distace[currentComputer] + 1;
				tracePath[nextComputer] = currentComputer;
				queueComputer.emplace(nextComputer);
			}
		}
	}
	if (distace[numComputer - 1] == -1) {
		std::cout << "IMPOSSIBLE";
	} else {
		int currentComputer = numComputer - 1;
		std::vector<int> path;
		while (currentComputer != 0) {
			path.emplace_back(currentComputer);
			currentComputer = tracePath[currentComputer];
		}
		reverse(path.begin(), path.end());
		std::cout << path.size() + 1 << '\n' << 1 << ' ';
		for (int computer : path) {
			std::cout << computer + 1 << ' ';
		}
	}
	return 0;
}