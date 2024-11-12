#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	std::vector<std::pair<int, char>> cows(numCow);
	for (auto &[position, say] : cows) {
		std::cin >> say >> position;
	}
	sort(cows.begin(), cows.end());
	std::vector<int> prefix(numCow);
	for (int index = 1; index < numCow; index++) {
		prefix[index] = prefix[index - 1];
		if (cows[index - 1].second == 'L' && cows[index].first >= cows[index - 1].first) {
			prefix[index]++;
		}
	}
	std::vector<int> suffix(numCow);
	for (int index = numCow - 2; index >= 0; index--) {
		suffix[index] = suffix[index + 1];
		if (cows[index + 1].second == 'G' && cows[index].first <= cows[index + 1].first) {
			suffix[index]++;
		}
	}
	int result = numCow;
	for (int index = 0; index < numCow; index++) {
		result = std::min(result, prefix[index] + suffix[index]);
	}
	std::cout << result;
	return 0;
}