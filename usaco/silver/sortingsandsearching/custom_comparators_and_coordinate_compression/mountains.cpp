#include <bits/stdc++.h>

int main() {
	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numMountain;
	std::cin >> numMountain;
	std::vector<std::pair<int, int>> segments;
	for (int index = 0; index < numMountain; index++) {
		int x, y;
		std::cin >> x >> y;
		segments.emplace_back(x - y, x + y);
	}
	sort(segments.begin(), segments.end(), [](std::pair<int, int> segment1, std::pair<int, int> segment2) {
		if (segment1.first == segment2.first) {
			return segment1.second > segment2.second;
		}
		return segment1.first < segment2.first;
	});
	int result = 0, maxRight = -1e9;
	for (auto [left, right] : segments) {
		if (right > maxRight) {
			maxRight = right;
			result++;
		}
	}
	std::cout << result;
	return 0;
}