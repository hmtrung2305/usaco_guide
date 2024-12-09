#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	std::vector<std::vector<int>> adjacent(numCow), reverseAdjacent(numCow);
	for (int cow = 0; cow < numCow; cow++) {
		adjacent[cow].resize(numCow);
		for (int index = 0; index < numCow; index++) {
			std::cin >> adjacent[cow][index];
			adjacent[cow][index]--;
		}
		while (adjacent[cow].back() != cow) {
			adjacent[cow].pop_back();
		}
		for (const int &neighbor : adjacent[cow]) {
			reverseAdjacent[neighbor].emplace_back(cow);
		}
	}
	std::vector<int> visited(numCow, false);
	std::vector<int> path;
	std::function<void(int)> depthFirstSearch1 = [&](int currentCow) {
		visited[currentCow] = true;
		for (const int &nextCow : adjacent[currentCow]) {
			if (!visited[nextCow]) {
				depthFirstSearch1(nextCow);
			}
		}
		path.emplace_back(currentCow);
	};
	for (int cow = 0; cow < numCow; cow++) {
		if (!visited[cow]) {
			depthFirstSearch1(cow);
		}
	}
	reverse(path.begin(), path.end());
	visited.assign(numCow, false);
	std::vector<int> result(numCow);
	std::vector<int> beComponent(numCow, false);
	for (const int &cow : path) {
		if (!visited[cow]) {
			std::vector<int> currentComponent;
			std::function<void(int)> depthFirstSearch2 = [&](int currentCow) {
				visited[currentCow] = true;
				for (const int &nextCow : reverseAdjacent[currentCow]) {
					if (!visited[nextCow]) {
						depthFirstSearch2(nextCow);
					}
				}
				beComponent[currentCow] = true;
				currentComponent.emplace_back(currentCow);
			};
			depthFirstSearch2(cow);
			for (const int &cowInComponent : currentComponent) {
				for (const int &gift : adjacent[cowInComponent]) {
					if (beComponent[gift]) {
						result[cowInComponent] = gift;
						break;
					}
				}
			}
			for (const int &cowInComponent : currentComponent) {
				beComponent[cowInComponent] = false;
			}
		}
	}
	for (const int &gift : result) {
		std::cout << gift + 1 << '\n';
	}
	return 0;
}