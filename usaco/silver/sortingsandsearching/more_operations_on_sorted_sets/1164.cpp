#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCustomer;
	std::cin >> numCustomer;
	std::vector<std::pair<std::pair<int, int>, int>> times(numCustomer);
	for (int index = 0; index < numCustomer; index++) {
		std::cin >> times[index].first.first >> times[index].first.second;
		times[index].second = index;
	}
	sort(times.begin(), times.end());
	int countRoom = 0;
	std::vector<int> result(numCustomer);
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> heapMin;
	for (int index = 0; index < numCustomer; index++) {
		if (heapMin.empty() || heapMin.top().first >= times[index].first.first) {
			countRoom++;
			heapMin.emplace(times[index].first.second, countRoom);
			result[times[index].second] = countRoom;
		} else {
			std::pair<int, int> minTime = heapMin.top();
			heapMin.pop();
			heapMin.emplace(times[index].first.second, minTime.second);
			result[times[index].second] = minTime.second;
		}
	}
	std::cout << countRoom << '\n';
	for (int room : result) {
		std::cout << room << ' ';
	}
	return 0;
}