#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	int countOdd = 0, countEven = 0;
	for (int index = 0; index < numCow; index++) {
		int breedID;
		std::cin >> breedID;
		if (breedID & 1) {
			countOdd++;
		} else {
			countEven++;
		}
	}
	while (countOdd > countEven) {
		countOdd -= 2;
		countEven++;
	}
	if (countEven > countOdd + 1) {
		countEven = countOdd + 1;
	}
	std::cout << countEven + countOdd;
	return 0;
}