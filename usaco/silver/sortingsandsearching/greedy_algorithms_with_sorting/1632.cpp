#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numMovie, numMember;
	std::cin >> numMovie >> numMember;
	std::vector<std::pair<int, int>> times(numMovie);
	for (auto &[starting, ending] : times) {
		std::cin >> starting >> ending;
	}
	sort(times.begin(), times.end());
	std::multiset<int> setTime;
	int result = 0;
	for (auto [starting, ending] : times) {
		while (!setTime.empty() && *setTime.begin() <= starting) {
			setTime.erase(setTime.begin());
		}
		if ((int)setTime.size() < numMember) {
			result++;
			setTime.insert(ending);
		} else if (*setTime.rbegin() > ending) {
			auto iter = setTime.end();
			iter--;
			setTime.erase(iter);
			setTime.insert(ending);
		}
	}
	std::cout << result;
	return 0;
}