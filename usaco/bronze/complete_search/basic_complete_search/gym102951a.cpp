#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numPoint;
	std::cin >> numPoint;
	std::vector<int> xCoordinates(numPoint);
	for (int &x : xCoordinates) {
		std::cin >> x;
	}
	std::vector<int> yCoordinates(numPoint);
	for (int &y : yCoordinates) {
		std::cin >> y;
	}
	int result = 0;
	for (int index1 = 0; index1 < numPoint; index1++) {
		for (int index2 = index1 + 1; index2 < numPoint; index2++) {
			int differenceX = xCoordinates[index1] - xCoordinates[index2];
			int differenceY = yCoordinates[index1] - yCoordinates[index2];
			result = std::max(result, differenceX * differenceX + differenceY * differenceY);
		}
	}
	std::cout << result;
	return 0;
}