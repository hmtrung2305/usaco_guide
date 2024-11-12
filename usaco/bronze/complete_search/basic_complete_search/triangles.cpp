#include <bits/stdc++.h>

int main() {
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numPoint;
	std::cin >> numPoint;
	std::vector<std::pair<int, int>> point(numPoint);
	for (auto &[x, y] : point) {
		std::cin >> x >> y;
	}
	int result = 0;
	for (int point1 = 0; point1 < numPoint; point1++) {
		for (int point2 = 0; point2 < numPoint; point2++) {
			for (int point3 = 0; point3 < numPoint; point3++) {
				if (point[point1].first == point[point2].first && point[point1].second == point[point3].second) {
					result = std::max(result, abs(point[point1].second - point[point2].second) * abs(point[point1].first - point[point3].first));
				}
			}
		}
	}
	std::cout << result;
	return 0;
}