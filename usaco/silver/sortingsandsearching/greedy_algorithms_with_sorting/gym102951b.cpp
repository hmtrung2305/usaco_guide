#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numAlgorithm, totalTime;
	std::cin >> numAlgorithm >> totalTime;
	std::vector<int> times(numAlgorithm);
	for (int &time : times) {
		std::cin >> time;
	}
	sort(times.begin(), times.end());
	int result = 0;
	for (int time : times) {
		if (totalTime < time) {
			break;
		}
		totalTime -= time;
		result++;
	}
	std::cout << result;
	return 0;
}