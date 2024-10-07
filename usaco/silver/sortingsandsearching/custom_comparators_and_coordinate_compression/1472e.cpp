#include <bits/stdc++.h>

struct Minimum2 {
	std::pair<int, int> min1, min2;
};

std::vector<std::pair<int, Minimum2>> createPrefixMin(const std::vector<std::array<int, 3>>& arr) {
	std::vector<std::pair<int, Minimum2>> prefixMin;
	Minimum2 currentMin{std::make_pair(INT_MAX, -1), std::make_pair(INT_MAX, -1)};
	for (std::array<int, 3> num : arr) {
		if (num[1] < currentMin.min1.first) {
			currentMin.min2 = currentMin.min1;
			currentMin.min1 = std::make_pair(num[1], num[2]);
		} else {
			currentMin.min2 = std::min(currentMin.min2, std::make_pair(num[1], num[2]));
		}
		prefixMin.emplace_back(num[0], currentMin);
	}
	return prefixMin;
}

int findPosition(const std::vector<std::pair<int, Minimum2>>& prefixMin, int height, int width, int index) {
	int low = 0, high = (int)prefixMin.size() - 1, findIndex = -1;
	while (low <= high) {
		int middle = (low + high) >> 1;
		if (prefixMin[middle].first < height) {
			findIndex = middle;
			low = middle + 1;
		} else {
			high = middle - 1;
		}
	}
	if (findIndex == -1) {
		return -1;
	}
	std::pair<int, int> min1 = prefixMin[findIndex].second.min1;
	std::pair<int, int> min2 = prefixMin[findIndex].second.min2;
	if (min1.second != index) {
		return min1.first < width ? min1.second + 1 : -1;
	}
	return min2.first < width ? min2.second + 1 : -1;
};


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int numFriend;
		std::cin >> numFriend;
		std::vector<std::pair<int, int>> friends(numFriend);
		std::vector<std::array<int, 3>> heights, widths;
		for (int index = 0; index < numFriend; index++) {
			std::cin >> friends[index].first >> friends[index].second;
			heights.push_back({friends[index].first, friends[index].second, index});
			widths.push_back({friends[index].second, friends[index].first, index});
		}
		sort(heights.begin(), heights.end());
		sort(widths.begin(), widths.end());
		std::vector<std::pair<int, Minimum2>> prefixMinHeight = createPrefixMin(heights);
		std::vector<std::pair<int, Minimum2>> prefixMinWidth = createPrefixMin(widths);
		for (int index = 0; index < numFriend; index++) {
			auto [height, width] = friends[index];
			int findIndex = findPosition(prefixMinHeight, height, width, index);
			if (findIndex == -1) {
				findIndex = findPosition(prefixMinWidth, height, width, index);
			}
			std::cout << findIndex << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}