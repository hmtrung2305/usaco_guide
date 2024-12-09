#include <bits/stdc++.h>

int main() {
	freopen("family.in", "r", stdin);
	freopen("family.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numName;
	std::vector<std::string> cows(2);
	std::cin >> numName >> cows[0] >> cows[1];
	std::map<std::string, std::string> edge;
	for (int index = 0; index < numName; index++) {
		std::string u, v;
		std::cin >> v >> u;
		edge[u] = v;
	}
	std::vector<std::map<std::string, int>> ancestor(2);
	for (int cow = 0; cow < 2; cow++) {
		std::string position = cows[cow];
		ancestor[cow][position] = 0;
		while (edge.count(position) != 0) {
			auto nextCow = edge.find(position);
			ancestor[cow][nextCow->second] = ancestor[cow][position] + 1;
			position = nextCow->second;
		}
	}
	std::string common;
	int distanceCow0 = 1e9, distanceCow1 = 1e9;
	for (const std::pair<std::string, int> &distance0 : ancestor[0]) {
		auto distance1 = ancestor[1].find(distance0.first);
		if (distance1 != ancestor[1].end() && (distanceCow0 > distance0.second || distanceCow1 > distance1->second)) {
			common = distance0.first;
			distanceCow0 = distance0.second;
			distanceCow1 = distance1->second;
		}
	}
	if (common.empty()) {
		std::cout << "NOT RELATED";
	} else if (common == cows[0] || common == cows[1]) {
		if (common == cows[0]) {
			std::swap(cows[0], cows[1]);
			std::swap(distanceCow0, distanceCow1);
		}
		std::cout << cows[1] << " is the ";
		if (distanceCow0 >= 2) {
			for (int index = 0; index < distanceCow0 - 2; index++) {
				std::cout << "great-";
			}
			std::cout << "grand-";
		}
		std::cout << "mother of " << cows[0];
	} else {
		if (distanceCow0 > distanceCow1) {
			std::swap(cows[0], cows[1]);
			std::swap(distanceCow0, distanceCow1);
		}
		if (distanceCow0 == 1) {
			if (distanceCow1 == 1) {
				std::cout << "SIBLINGS";
			} else {
				std::cout << cows[0] << " is the ";
				for (int index = 0; index < distanceCow1 - 2; index++) {
					std::cout << "great-";
				}
				std::cout << "aunt of " << cows[1];
			}
		} else {
			std::cout << "COUSINS";
		}
	}
	return 0;
}