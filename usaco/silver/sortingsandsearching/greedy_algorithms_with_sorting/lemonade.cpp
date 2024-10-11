#include <bits/stdc++.h>

int main() {
	freopen("lemonade.in", "r", stdin);
	freopen("lemonade.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	std::vector<int> maxBehindCow(numCow);
	for (int &maxBehind : maxBehindCow) {
		std::cin >> maxBehind;
	}
	sort(maxBehindCow.begin(), maxBehindCow.end(), std::greater<int>());
	int result = 0;
	for (int index = 0; index < numCow; index++) {
		if (maxBehindCow[index] >= index) {
			result++;
		} else {
			break;
		}
	}
	std::cout << result;
	return 0;
}