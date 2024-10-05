#include <bits/stdc++.h>

int main() {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	std::vector<std::pair<int, int>> timeCow(numCow);
	for (int index = 0; index < numCow; index++) {
		std::cin >> timeCow[index].first >> timeCow[index].second;
	}
	sort(timeCow.begin(), timeCow.end());
	int totalTime = 0;
	for (int index = 0, left = 0, right = 0; index < numCow; index++) {
		if (timeCow[index].second > right) {
			left = std::max(right, timeCow[index].first);
			totalTime += timeCow[index].second - left;
			right = timeCow[index].second;
		}
	}
	timeCow.emplace_back(timeCow[numCow - 1].second, 0);
	int minTime = totalTime;
	for (int index = 0, right = 0; index < numCow; index++) {
		int current = std::min(timeCow[index + 1].first, timeCow[index].second) - std::max(right, timeCow[index].first);
		minTime = std::min(minTime, current);
		right = std::max(right, timeCow[index].second);
	}
	std::cout << totalTime - std::max(0, minTime);
	return 0;
}