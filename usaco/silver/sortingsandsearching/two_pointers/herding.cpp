#include <bits/stdc++.h>

int main() {
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	std::vector<int> positionCow(numCow);
	for (int &position : positionCow) {
		std::cin >> position;
	}
	sort(positionCow.begin(), positionCow.end());
	int minMove = 2e9;
	if (positionCow[numCow - 2] - positionCow[0] == numCow - 2 && positionCow[numCow - 1] - positionCow[numCow - 2] > 2) {
		minMove = 2;
	} else if (positionCow[numCow - 1] - positionCow[1] == numCow - 2 && positionCow[1] - positionCow[0] > 2) {
		minMove = 2;
	} else {
		int furthestCow = 0;
		for (int currentCow = 0; currentCow < numCow; currentCow++) {
			while (furthestCow + 1 < numCow && positionCow[furthestCow + 1] - positionCow[currentCow] < numCow) {
				furthestCow++;
			}
			minMove = std::min(minMove, numCow - (furthestCow - currentCow + 1));
		}
	}
	int totalGap = 0;
	for (int index = 0; index < numCow - 1; index++) {
		totalGap += positionCow[index + 1] - positionCow[index] - 1;
	}
	int maxMove = std::max(totalGap - (positionCow[1] - positionCow[0] - 1), totalGap - (positionCow[numCow - 1] - positionCow[numCow - 2] - 1));
	std::cout << minMove << '\n' << maxMove;
	return 0;
}