#include <bits/stdc++.h>

int main() {
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numVideo, numQuery;
	std::cin >> numVideo >> numQuery;
	std::vector<std::vector<std::pair<int, int>>> adjacent(numVideo);
	for (int pair = 1; pair < numVideo; pair++) {
		int u, v, relevance;
		std::cin >> u >> v >> relevance;
		u--; v--;
		adjacent[u].emplace_back(v, relevance);
		adjacent[v].emplace_back(u, relevance);
	}
	int threshold = 0, countConnect = 0;
	std::function<void(int, int)> depthFirstSearch = [&](int currentVideo, int previousVideo) {
		for (const auto &[nextVideo, relevance] : adjacent[currentVideo]) {
			if (nextVideo != previousVideo && threshold <= relevance) {
				countConnect++;
				depthFirstSearch(nextVideo, currentVideo);
			}
		}
	};
	while (numQuery--) {
		int video;
		std::cin >> threshold >> video;
		video--;
		countConnect = 0;
		depthFirstSearch(video, -1);
		std::cout << countConnect << '\n';
	}
	return 0;
}