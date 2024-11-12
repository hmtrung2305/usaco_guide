#include <bits/stdc++.h>

int main() {
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	std::vector<int> shuffle(numCow);
	for (int &num : shuffle) {
		std::cin >> num;
		num--;
	}
	std::vector<int> idCow(numCow);
	for (int &id : idCow) {
		std::cin >> id;
	}
	for (int time = 0; time < 3; time++) {
		std::vector<int> previousIndex(numCow);
		for (int index = 0; index < numCow; index++) {
			previousIndex[index] = idCow[shuffle[index]];
		}
		idCow = previousIndex;
	}
	for (int &id : idCow) {
		std::cout << id << '\n';
	}
	return 0;
}