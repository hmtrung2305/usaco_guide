#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int numOpponent, limitTime;
		std::cin >> numOpponent >> limitTime;
		std::vector<int> timePrepare(numOpponent);
		for (int &time : timePrepare) {
			std::cin >> time;
		}
		std::vector<int> timeSorted(timePrepare);
		sort(timeSorted.begin(), timeSorted.end());
		std::vector<int> prefixSumTime(numOpponent + 1);
		for (int index = 0; index < numOpponent; index++) {
			prefixSumTime[index + 1] = prefixSumTime[index] + timeSorted[index];
		}
		int result = numOpponent + 1;
		for (int index = 1; index <= numOpponent; index++) {
			if (index < numOpponent && limitTime >= prefixSumTime[index] + std::max(0, timePrepare[index] - timeSorted[index - 1])) {
				result = numOpponent - index;
			} else if (limitTime >= prefixSumTime[index]) {
				result = numOpponent - index + 1;
			} else {
				break;
			}
		}
		std::cout << result << '\n';
	}
	return 0;
}