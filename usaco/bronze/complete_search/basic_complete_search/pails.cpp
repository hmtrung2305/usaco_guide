#include <bits/stdc++.h>

int main() {
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int sizePailX, sizePailY, sizeTarget;
	std::cin >> sizePailX >> sizePailY >> sizeTarget;
	int result = 0;
	for (int timePailX = 0; timePailX <= 1000; timePailX++) {
		for (int timePailY = 0; timePailY <= 1000; timePailY++) {
			if (timePailX * sizePailX + timePailY * sizePailY > sizeTarget) {
				continue;
			}
			result = std::max(result, timePailX * sizePailX + timePailY * sizePailY);
		}
	}
	std::cout << result;
	return 0;
}