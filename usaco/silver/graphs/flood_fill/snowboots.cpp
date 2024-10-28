// Greedy - Time Complexity: O(numTile * numBoot)
#include <bits/stdc++.h>

int main() {
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTile, numBoot;
	std::cin >> numTile >> numBoot;
	std::vector<int> feetSnow(numTile);
	for (int &feet : feetSnow) {
		std::cin >> feet;
	}
	std::queue<std::pair<int, int>> queueBoot;
	for (int index = 0; index < numBoot; index++) {
		int depth, distance;
		std::cin >> depth >> distance;
		queueBoot.emplace(depth, distance);
	}
	int currentTile = 0, discarded = 0;
	while (currentTile < numTile - 1 && !queueBoot.empty()) {
		auto [currentDepth, currentDistance] = queueBoot.front();
		queueBoot.pop();
		int previousTile = currentTile;
		while (currentDepth < feetSnow[currentTile]) {
			currentTile--;
		}
		int canStep = true;
		while (canStep) {
			canStep = false;
			int distance = currentDistance;
			while (currentTile + distance > numTile - 1 || feetSnow[currentTile + distance] > currentDepth) {
				distance--;
			}
			if (distance > 0) {
				currentTile += distance;
				canStep = true;
			}
		}
		currentTile = std::max(currentTile, previousTile);
		discarded++;
	}
	std::cout << discarded - 1;
	return 0;
}