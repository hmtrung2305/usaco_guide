#include <bits/stdc++.h>

std::vector<std::string> names = {"Beatrice", "Sue", "Belinda", "Bessie", "Betsy", "Blue", "Bella", "Buttercup"};

int main() {
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numRequire;
	std::cin >> numRequire;
	std::vector<std::pair<std::string, std::string>> pairs;
	while (numRequire--) {
		std::pair<std::string, std::string> pair;
		std::string temporary;
		std::cin >> pair.first >> temporary >> temporary >> temporary >> temporary >> pair.second;
		pairs.emplace_back(pair);
	}
	sort(names.begin(), names.end());
	do {
		bool satisfyCondition = true;
		for (const std::pair<std::string, std::string> &pair : pairs) {
			for (int index = 0; index < 8; index++) {
				if (pair.first == names[index] && index > 0 && index < 7) {
					if (pair.second != names[index - 1] && pair.second != names[index + 1]) {
						satisfyCondition = false;
					}
				}
				if (pair.first == names[index] && index == 0 && pair.second != names[index + 1]) {
					satisfyCondition = false;
				}
				if (pair.first == names[index] && index == 7 && pair.second != names[index - 1]) {
					satisfyCondition = false;
				}
			}
		}
		if (satisfyCondition) {
			break;
		}
	} while (next_permutation(names.begin(), names.end()));
	for (const std::string &name : names) {
		std::cout << name << '\n';
	}
	return 0;
}