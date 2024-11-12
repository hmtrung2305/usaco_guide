#include <bits/stdc++.h>

const std::vector<std::string> NAMES{"Bessie", "Elsie", "Mildred"};
const int START_AMOUNT = 7;

int main() {
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numUpdate;
	std::cin >> numUpdate;
	std::vector<std::tuple<int, std::string, int>> updates;
	for (int index = 0; index < numUpdate; index++) {
		int day, change;
		std::string name;
		std::cin >> day >> name >> change;
		updates.emplace_back(day, name, change);
	}
	sort(updates.begin(), updates.end());
	std::map<std::string, int> outputCow;
	for (const std::string name : NAMES) {
		outputCow[name] = START_AMOUNT;
	}
	int displayChange = 0;
	std::vector<std::string> display = NAMES;
	for (const auto &[dayUpdate, nameUpdate, changeUpdate] : updates) {
		outputCow[nameUpdate] += changeUpdate;
		int maxOutput = 0;
		for (const std::string name : NAMES) {
			maxOutput = std::max(maxOutput, outputCow[name]);
		}
		std::vector<std::string> newDisplay;
		for (const std::string name : NAMES) {
			if (maxOutput == outputCow[name]) {
				newDisplay.emplace_back(name);
			}
		}
		if (display != newDisplay) {
			displayChange++;
		}
		display = newDisplay;
	}
	std::cout << displayChange;
	return 0;
}