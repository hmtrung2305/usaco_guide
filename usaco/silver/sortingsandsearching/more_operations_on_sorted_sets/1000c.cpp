#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numSegment;
	std::cin >> numSegment;
	std::vector<std::pair<long long, int>> pointSegment;
	for (int index = 0; index < numSegment; index++) {
		long long left, right;
		std::cin >> left >> right;
		pointSegment.emplace_back(left, 1);
		pointSegment.emplace_back(right + 1, -1);
	}
	sort(pointSegment.begin(), pointSegment.end());
	std::vector<long long> countCovered(numSegment + 1);
	int currentCovered = 0;
	long long previousPoint = 0;
	for (const auto &[point, state] : pointSegment) {
		countCovered[currentCovered] += point - previousPoint;
		currentCovered += state;
		previousPoint = point;
	}
	for (int covered = 1; covered <= numSegment; covered++) {
		std::cout << countCovered[covered] << ' ';
	}
	return 0;
}