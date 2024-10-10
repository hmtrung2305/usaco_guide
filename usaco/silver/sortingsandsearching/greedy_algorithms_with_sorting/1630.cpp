#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTask;
	std::cin >> numTask;
	std::vector<std::pair<int, int>> tasks(numTask);
	for (auto &[duration, deadline] : tasks) {
		std::cin >> duration >> deadline;
	}
	sort(tasks.begin(), tasks.end());
	long long result = 0, currentTime = 0;
	for (int index = 0; index < numTask; index++) {
		currentTime += tasks[index].first;
		result += tasks[index].second - currentTime;
	}
	std::cout << result;
	return 0;
}