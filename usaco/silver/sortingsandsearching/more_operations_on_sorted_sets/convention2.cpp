#include <bits/stdc++.h>

int main() {
	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	std::vector<std::vector<int>> cows;
	for (int seniority = 0; seniority < numCow; seniority++) {
		int start, duration;
		std::cin >> start >> duration;
		cows.push_back({seniority, start, duration});
	}
	sort(cows.begin(), cows.end(), [](const std::vector<int> &cow1, const std::vector<int> &cow2) {
		return cow1[1] < cow2[1];
	});
	int currentTime = 0, longestTimeWait = 0;
	int index = 0;
	std::set<std::vector<int>> setTimeWaiting;
	while (index < numCow || !setTimeWaiting.empty()) {
		if (index < numCow && cows[index][1] <= currentTime) {
			setTimeWaiting.insert(cows[index]);
			index++;
		} else if (setTimeWaiting.empty()) {
			currentTime = cows[index][1] + cows[index][2];
			index++;
		} else {
			std::vector<int> next = *setTimeWaiting.begin();
			longestTimeWait = std::max(longestTimeWait, currentTime - next[1]);
			currentTime += next[2];
			setTimeWaiting.erase(setTimeWaiting.begin());
		}
	}
	std::cout << longestTimeWait;
	return 0;
}