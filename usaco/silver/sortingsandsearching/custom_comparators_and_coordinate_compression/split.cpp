#include <bits/stdc++.h>

int main() {
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	std::vector<std::pair<int, int>> positions(numCow);
	for (auto &[x, y] : positions) {
		std::cin >> x >> y;
	}
	std::function<long long()> maxDiff = [&]() {
		sort(positions.begin(), positions.end());
		std::vector<std::pair<int, int>> prefixMaxMin(numCow);
		prefixMaxMin[0] = std::make_pair(positions[0].second, positions[0].second);
		for (int index = 1; index < numCow; index++) {
			prefixMaxMin[index] = std::make_pair(std::max(prefixMaxMin[index - 1].first, positions[index].second), std::min(prefixMaxMin[index - 1].second, positions[index].second));
		}
		std::vector<std::pair<int, int>> suffixMaxMin(numCow);
		suffixMaxMin[numCow - 1] = std::make_pair(positions[numCow - 1].second, positions[numCow - 1].second);
		for (int index = numCow - 2; index >= 0; index--) {
			suffixMaxMin[index] = std::make_pair(std::max(suffixMaxMin[index + 1].first, positions[index].second), std::min(suffixMaxMin[index + 1].second, positions[index].second));
		}
		long long totalArea = 1ll * (positions.back().first - positions.front().first) * (prefixMaxMin.back().first - prefixMaxMin.back().second);
		long long min2Area = 1e18;
		for (int index = 0; index < numCow - 1; index++) {
			if (positions[index].first != positions[index + 1].first) {
				long long areaRectangle1 = 1ll * (positions[index].first - positions[0].first) * (prefixMaxMin[index].first - prefixMaxMin[index].second);
				long long areaRectangle2 = 1ll * (positions.back().first - positions[index + 1].first) * (suffixMaxMin[index + 1].first - suffixMaxMin[index + 1].second);
				min2Area = std::min(min2Area, areaRectangle1 + areaRectangle2);
			}
		}
		return totalArea - min2Area;
	};
	long long result = maxDiff();
	for (auto &[x, y] : positions) {
		std::swap(x, y);
	}
	result = std::max(result, maxDiff());
	std::cout << result;
	return 0;
}