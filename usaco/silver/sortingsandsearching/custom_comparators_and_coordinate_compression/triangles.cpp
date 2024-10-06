#include <bits/stdc++.h>

const int LIMIT = 1e4;
const int MODULO = 1e9 + 7;

int main() {
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numFence;
	std::cin >> numFence;
	std::vector<std::array<long long, 4>> fences(numFence); // 0 = x, 1 = y, 2 = sumHeight, 3 = sumBase
	std::vector<std::vector<std::pair<int, int>>> xCoordinates(2 * LIMIT + 1), yCoordinates(2 * LIMIT + 1);
	for (int index = 0; index < numFence; index++) {
		std::cin >> fences[index][0] >> fences[index][1];
		xCoordinates[fences[index][0] + LIMIT].emplace_back(fences[index][1], index);
		yCoordinates[fences[index][1] + LIMIT].emplace_back(fences[index][0], index);
	}
	for (int x = 0; x <= 2 * LIMIT; x++) {
		if (xCoordinates[x].size() > 0) {
			sort(xCoordinates[x].begin(), xCoordinates[x].end());
			long long sum = 0;
			for (int index = 1; index < (int)xCoordinates[x].size(); index++) {
				sum += xCoordinates[x][index].first - xCoordinates[x][0].first;
			}
			fences[xCoordinates[x][0].second][2] = sum;
			for (int index = 1; index < (int)xCoordinates[x].size(); index++) {
				sum += (2 * index - (int)xCoordinates[x].size()) * (xCoordinates[x][index].first - xCoordinates[x][index - 1].first);
				fences[xCoordinates[x][index].second][2] = sum;
			}
		}
	}
	for (int y = 0; y <= 2 * LIMIT; y++) {
		if (yCoordinates[y].size() > 0) {
			sort(yCoordinates[y].begin(), yCoordinates[y].end());
			long long sum = 0;
			for (int index = 1; index < (int)yCoordinates[y].size(); index++) {
				sum += yCoordinates[y][index].first - yCoordinates[y][0].first;
			}
			fences[yCoordinates[y][0].second][3] = sum;
			for (int index = 1; index < (int)yCoordinates[y].size(); index++) {
				sum += (2 * index - (int)yCoordinates[y].size()) * (yCoordinates[y][index].first - yCoordinates[y][index - 1].first);
				fences[yCoordinates[y][index].second][3] = sum;
			}
		}
	}
	long long result = 0;
	for (int index = 0; index < numFence; index++) {
		result = (result + fences[index][2] * fences[index][3] % MODULO) % MODULO;
	}
	std::cout << result;
	return 0;
}