#include <bits/stdc++.h>

int main() {
	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow, maxTime;
	std::cin >> numCow >> maxTime;
	std::vector<int> durationCow(numCow);
	for (int &duration : durationCow) {
		std::cin >> duration;
	}
	int low = 1, high = numCow;
	int result = numCow;
	while (low <= high) {
		int middle = low + ((high - low + 1) >> 1);
		std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
		int size = 0, index = 0;
		while (size < middle && index < numCow) {
			minHeap.emplace(durationCow[index]);
			size++;
			index++;
		}
		int time = 0;
		while (!minHeap.empty()) {
			time += std::max(0, minHeap.top() - time);
			minHeap.pop();
			if (index < numCow) {
				minHeap.emplace(durationCow[index] + time);
				index++;
			}
		}
		if (time <= maxTime) {
			result = middle;
			high = middle - 1;
		} else {
			low = middle + 1;
		}
	}
	std::cout << result;
	return 0;
}