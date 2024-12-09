/*
practicing..
*/
#include <bits/stdc++.h>

int main() {
	freopen("clocktree.in", "r", stdin);
	freopen("clocktree.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numRoom;
	std::cin >> numRoom;
	std::vector<int> clockSetting(numRoom);
	for (int &clock : clockSetting) {
		std::cin >> clock;
	}
	std::vector<std::vector<int>> adjacent(numRoom);
	for (int corridor = 1; corridor < numRoom; corridor++) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		adjacent[u].emplace_back(v);
		adjacent[v].emplace_back(u);
	}
	std::array<int, 2> countType{0, 0}, sumType{0, 0};
	std::function<void(int, int, int)> depthFirstSearch = [&](int currentRoom, int previousRoom, int type) {
		countType[type]++;
		sumType[type] += clockSetting[currentRoom];
		for (const int &nextRoom : adjacent[currentRoom]) {
			if (nextRoom != previousRoom) {
				depthFirstSearch(nextRoom, currentRoom, 1 - type);
			}
		}
	};
	depthFirstSearch(0, -1, 0);
	if (sumType[0] % 12 == sumType[1] % 12) {
		std::cout << numRoom;
	} else if ((sumType[0] + 1) % 12 == sumType[1] % 12) {
		std::cout << countType[1];
	} else if (sumType[0] % 12 == (sumType[1] + 1) % 12) {
		std::cout << countType[0];
	} else {
		std::cout << 0;
	}
	return 0;
}