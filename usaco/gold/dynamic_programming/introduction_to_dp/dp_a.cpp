#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numStone;
	std::cin >> numStone;
	std::vector<int> heightStone(numStone);
	for (int &height : heightStone) {
		std::cin >> height;
	}
	std::vector<int> minCost(numStone);
	minCost[0] = 0;
	minCost[1] = abs(heightStone[1] - heightStone[0]);
	for (int index = 2; index < numStone; index++) {
		minCost[index] = std::min(
			minCost[index - 1] + abs(heightStone[index] - heightStone[index - 1]), 
			minCost[index - 2] + abs(heightStone[index] - heightStone[index - 2]));
	}
	std::cout << minCost[numStone - 1];
	return 0;
}