#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numPlanet;
	std::cin >> numPlanet;
	std::vector<int> teleporters(numPlanet);
	for (int &planet : teleporters) {
		std::cin >> planet;
		planet--;
	}
	std::vector<int> visitedPlanet(numPlanet, false);
	std::queue<int> path;
	int length = 0;
	std::vector<int> lengthPathPlanet(numPlanet);
	std::function<void(int)> depthFirstSearch = [&](int currentPlanet) {
		path.emplace(currentPlanet);
		if (visitedPlanet[currentPlanet]) {
			length += lengthPathPlanet[currentPlanet];
			return;
		}
		visitedPlanet[currentPlanet] = true;
		length++;
		depthFirstSearch(teleporters[currentPlanet]);
	};
	for (int planet = 0; planet < numPlanet; planet++) {
		if (!visitedPlanet[planet]) {
			length = 0;
			depthFirstSearch(planet);
			int isCycle = 1;
			while (!path.empty()) {
				if (path.front() == path.back()) {
					isCycle = 0;
				}
				lengthPathPlanet[path.front()] = length;
				length -= isCycle;
				path.pop();
			}
		}
	}
	for (const int &length : lengthPathPlanet) {
		std::cout << length << ' ';
	}
	return 0;
}