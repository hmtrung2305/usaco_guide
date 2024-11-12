#include <bits/stdc++.h>

int main() {
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numBarn;
	std::cin >> numBarn;
	std::vector<int> needCow(numBarn);
	for (int index = 0; index < numBarn; index++) {
		std::cin >> needCow[index];
	}
	int totalCow = accumulate(needCow.begin(), needCow.end(), 0);
	int result = 1e9;
	for (int openBarn = 0; openBarn < numBarn; openBarn++) {
		int currentDistance = 0;
		int currentCow = totalCow - needCow[openBarn];
		for (int barn = (openBarn + 1) % numBarn; barn != openBarn; barn = (barn + 1) % numBarn) {
			currentDistance += currentCow;
			currentCow -= needCow[barn];
		}
		result = std::min(result, currentDistance);
	}
	std::cout << result;
	return 0;
}