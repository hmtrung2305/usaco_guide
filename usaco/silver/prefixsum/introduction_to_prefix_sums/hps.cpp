#include <bits/stdc++.h>

int main() {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numGame;
	std::cin >> numGame;

	std::vector<std::vector<int>> prefixSum(numGame, std::vector<int>(3));
	for (int index = 0; index < numGame; index++) {
		char game;
		std::cin >> game;
		if (index > 0) {
			for (int type = 0; type < 3; type++) {
				prefixSum[index][type] = prefixSum[index - 1][type];				
			}
		}
		switch (game) {
		case 'H':
			prefixSum[index][0]++;
			break;
		case 'P':
			prefixSum[index][1]++;
			break;
		default:
			prefixSum[index][2]++;
			break;
		}
	}
	int result = 0;
	for (int index = 0; index < numGame; index++) {
		result = std::max(result, *std::max_element(prefixSum[index].begin(), prefixSum[index].end()) + prefixSum[numGame - 1][2] - prefixSum[index][2]);
		result = std::max(result, *std::max_element(prefixSum[index].begin(), prefixSum[index].end()) + prefixSum[numGame - 1][0] - prefixSum[index][0]);
		result = std::max(result, *std::max_element(prefixSum[index].begin(), prefixSum[index].end()) + prefixSum[numGame - 1][1] - prefixSum[index][1]);
	}
	std::cout << result;
	return 0;
}