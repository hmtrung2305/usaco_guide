#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int numQuest, needCompleted;
		std::cin >> numQuest >> needCompleted;
		std::vector<int> experienceFirstTimeQuest(numQuest);
		for (int &experience : experienceFirstTimeQuest) {
			std::cin >> experience;
		}
		std::vector<int> experienceNextTimeQuest(numQuest);
		for (int &experience : experienceNextTimeQuest) {
			std::cin >> experience;
		}
		int result = 0;
		for (int quest = 0, sumPrefix = 0, maxPrefix = 0; quest < std::min(numQuest, needCompleted); quest++) {
			sumPrefix += experienceFirstTimeQuest[quest];
			maxPrefix = std::max(maxPrefix, experienceNextTimeQuest[quest]);
			result = std::max(result, sumPrefix + maxPrefix * (needCompleted - quest - 1));
		}
		std::cout << result << '\n';
	}
	return 0;
}