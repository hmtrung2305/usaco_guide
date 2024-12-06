#include <bits/stdc++.h>

int main() {
	freopen("berries.in", "r", stdin);
	freopen("berries.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTree, numBasket;
	std::cin >> numTree >> numBasket;
	std::vector<int> berryTree(numTree);
	for (int &berry : berryTree) {
		std::cin >> berry;
	}
	int maxBerry = *max_element(berryTree.begin(), berryTree.end());
	int result = 0;
	for (int limitBerry = 1; limitBerry <= maxBerry; limitBerry++) {
		int fullBasket = 0;
		for (const int &berry : berryTree) {
			fullBasket += berry / limitBerry;
		}
		if (fullBasket < numBasket / 2) {
			break;
		}
		if (fullBasket >= numBasket) {
			result = std::max(result, limitBerry * (numBasket / 2));
			continue;
		}
		sort(berryTree.begin(), berryTree.end(), [&](const int &numLeftSide, const int &numRightSide) {
			return numLeftSide % limitBerry > numRightSide % limitBerry;
		});
		int current = limitBerry * (fullBasket - numBasket / 2);
		for (int index = 0; index < numTree && index + fullBasket < numBasket; index++) {
			current += berryTree[index] % limitBerry;
		}
		result = std::max(result, current);
	}
	std::cout << result;
	return 0;
}