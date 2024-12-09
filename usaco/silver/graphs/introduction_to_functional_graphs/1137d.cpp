#include <bits/stdc++.h>

int main() {
	std::function<std::vector<int>(std::vector<int>)> resultMove = [](const std::vector<int> &groupMove) {
		std::cout << "next ";
		for (int index = 0; index < (int)groupMove.size() - 1; index++) {
			std::cout << groupMove[index] << ' ';
		}
		std::cout << groupMove.back() << '\n';
		int numGroup;
		std::cin >> numGroup;
		std::vector<int> nextGroup(10);
		for (int index = 0; index < numGroup; index++) {
			std::string group;
			std::cin >> group;
			for (const char &g : group) {
				nextGroup[g - '0'] = index;
			}
		}
		return nextGroup;
	};
	resultMove({0, 1});
	std::vector<int> groups = resultMove({1});
	while (groups[0] != groups[1]) {
		resultMove({0, 1});
		groups = resultMove({1});
	}
	while (groups[1] != groups[2]) {
		groups = resultMove({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
	}
	std::cout << "done";
	return 0;
}