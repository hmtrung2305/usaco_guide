#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numMovie;
	std::cin >> numMovie;
	std::vector<std::pair<int, int>> movies(numMovie);
	for (auto &[starting, ending] : movies) {
		std::cin >> starting >> ending;
	}
	sort(movies.begin(), movies.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
		return a.second < b.second;
	});
	int maxEnding = 0;
	int result = 0;
	for (auto [starting, ending] : movies) {
		if (maxEnding <= starting) {
			maxEnding = ending;
			result++;
		}
	}
	std::cout << result;
	return 0;
}