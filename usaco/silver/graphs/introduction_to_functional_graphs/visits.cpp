#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numBuddy;
	std::cin >> numBuddy;
	std::vector<int> wantToVisit(numBuddy), moo(numBuddy);
	long long result = 0;
	std::vector<std::vector<int>> reverseGraph(numBuddy);
	for (int index = 0; index < numBuddy; index++) {
		std::cin >> wantToVisit[index] >> moo[index];
		wantToVisit[index]--;
		reverseGraph[wantToVisit[index]].emplace_back(index);
		result += moo[index];
	}
	std::vector<bool> visitedBuddy(numBuddy, false);
	std::function<void(int)> findVisited = [&](int buddy) {
		visitedBuddy[buddy] = true;
		for (const int &previousBuddy : reverseGraph[buddy]) {
			if (!visitedBuddy[previousBuddy]) {
				findVisited(previousBuddy);
			}
		}
	};
	// floyd's algorithm
	std::function<int(int)> minInCycle = [&](int buddy) {
		int buddy1 = wantToVisit[buddy];
		int buddy2 = wantToVisit[buddy1];
		while (buddy1 != buddy2) {
			buddy1 = wantToVisit[buddy1];
			buddy2 = wantToVisit[wantToVisit[buddy2]];
		}
		int minValue = moo[buddy1];
		buddy1 = wantToVisit[buddy1];
		while (buddy1 != buddy2) {
			minValue = std::min(minValue, moo[buddy1]);
			buddy1 = wantToVisit[buddy1];
		}
		findVisited(buddy1);
		return minValue;
	};
	for (int index = 0; index < numBuddy; index++) {
		if (!visitedBuddy[index]) {
			result -= minInCycle(index);
		}
	}
	std::cout << result;
	return 0;
}