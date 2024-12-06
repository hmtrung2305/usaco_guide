#include <bits/stdc++.h>

int main() {
	freopen("helpcross.in", "r", stdin);
	freopen("helpcross.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numChicken, numCow;
	std::cin >> numChicken >> numCow;
	std::multiset<int> setTimeChicken;
	for (int index = 0; index < numChicken; index++) {
		int time;
		std::cin >> time;
		setTimeChicken.insert(time);
	}
	std::vector<std::pair<int, int>> timeCow(numCow);
	for (auto &[right, left] : timeCow) {
		std::cin >> left >> right;
	}
	sort(timeCow.begin(), timeCow.end());
	int result = 0;
	for (const auto &[right, left] : timeCow) {
		auto timeChicken = setTimeChicken.lower_bound(left);
		if (timeChicken != setTimeChicken.end() && *timeChicken <= right) {
			result++;
			setTimeChicken.erase(timeChicken);
		}
	}
	std::cout << result;
	return 0;
}