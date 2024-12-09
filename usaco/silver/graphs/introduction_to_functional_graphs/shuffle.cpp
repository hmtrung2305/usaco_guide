#include <bits/stdc++.h>

int main() {
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	std::vector<int> positionAfterSuffle(numCow);
	std::vector<int> countCowPosition(numCow, 0);
	for (int &position : positionAfterSuffle) {
		std::cin >> position;
		position--;
		countCowPosition[position]++;
	}
	int result = numCow;
	std::queue<int> queuePosition;
	for (int position = 0; position < numCow; position++) {
		if (countCowPosition[position] == 0) {
			queuePosition.emplace(positionAfterSuffle[position]);
			result--;
		}
	}
	while (!queuePosition.empty()) {
		int position = queuePosition.front();
		queuePosition.pop();
		countCowPosition[position]--;
		if (countCowPosition[position] == 0) {
			result--;
			queuePosition.emplace(positionAfterSuffle[position]);
		}
	}
	std::cout << result;
	return 0;
}