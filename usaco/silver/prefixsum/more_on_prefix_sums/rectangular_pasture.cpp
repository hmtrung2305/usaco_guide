#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	std::vector<std::pair<int, int>> positionCow(numCow);
	for (auto &[x, y] : positionCow) {
		std::cin >> x >> y;
	}
	sort(positionCow.begin(), positionCow.end());
	for (int index = 0; index < numCow; index++) {
		positionCow[index].first = index;
	}
	sort(positionCow.begin(), positionCow.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
		return a.second < b.second;
	});
	for (int index = 0; index < numCow; index++) {
		positionCow[index].second = index;
	}
	std::vector<std::vector<int>> prefixSum(numCow + 1, std::vector<int>(numCow + 1, 0));
	for (int index = 0; index < numCow; index++) {
		prefixSum[positionCow[index].first + 1][positionCow[index].second + 1] = 1;
	}
	for (int row = 1; row <= numCow; row++) {
		for (int column = 1; column <= numCow; column++) {
			prefixSum[row][column] += prefixSum[row - 1][column] + prefixSum[row][column - 1] - prefixSum[row - 1][column - 1];
		}
	}
	long long result = 0;
	for (int indexLeft = 0; indexLeft < numCow; indexLeft++) {
		for (int indexRight = indexLeft; indexRight < numCow; indexRight++) {
			int left = std::min(positionCow[indexLeft].first, positionCow[indexRight].first) + 1;
			int right = std::max(positionCow[indexLeft].first, positionCow[indexRight].first) + 1;
			
			result += 
				(prefixSum[left][indexRight + 1] - prefixSum[left][indexLeft] - prefixSum[0][indexLeft] + prefixSum[0][indexLeft]) * // [1][indexLeft + 1] to [left][indexRight + 1]
				(prefixSum[numCow][indexRight + 1] - prefixSum[numCow][indexLeft] - prefixSum[right - 1][indexRight + 1] + prefixSum[right - 1][indexLeft]); // [right][indexLeft + 1] to [numCow][indexRight + 1]
		}
	}
	std::cout << result + 1 << '\n';
	return 0;
}