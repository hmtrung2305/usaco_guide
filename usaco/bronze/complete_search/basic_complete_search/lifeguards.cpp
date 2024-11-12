#include <bits/stdc++.h>

const int TIME = 1000;

int main() {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numLifeguard;
	std::cin >> numLifeguard;
	std::vector<std::pair<int, int>> timeLifeguard(numLifeguard);
	for (auto &[left, right] : timeLifeguard) {
		std::cin >> left >> right;
	}
	int maxCovered = 0;
	for (int removed = 0; removed < numLifeguard; removed++) {
		int covered = 0;
		for (int time = 1; time <= TIME; time++) {
			for (int index = 0; index < numLifeguard; index++) {
				if (index != removed) {
					if (timeLifeguard[index].first <= time && time < timeLifeguard[index].second) {
						covered++;
						break;
					}
				}
			}
		}
		maxCovered = std::max(maxCovered, covered);
	}
	std::cout << maxCovered;
	return 0;
}