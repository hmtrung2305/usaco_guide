#include <bits/stdc++.h>

int main() {
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int distance, numStop, speedFarmer, speedCow;
	std::cin >> distance >> numStop >> speedFarmer >> speedCow;
	std::vector<int> positionStop(numStop), tastinessStop(numStop);
	for (int index = 0; index < numStop; index++) {
		std::cin >> positionStop[index] >> tastinessStop[index];
	}
	std::vector<bool> stopped(numStop, false);
	int currentMaxTastiness = 0;
	for (int index = numStop - 1; index >= 0; index--) {
		if (tastinessStop[index] > currentMaxTastiness) {
			currentMaxTastiness = tastinessStop[index];
			stopped[index] = true;
		}
	}
	int previousPosition = 0;
	long long result = 0;
	for (int index = 0; index < numStop; index++) {
		if (stopped[index]) {
			long long currentDistance = positionStop[index] - previousPosition;
			long long timeFarmer = currentDistance * speedFarmer;
			long long timeCow = currentDistance * speedCow;
			long long timeRest = timeFarmer - timeCow;
			result += timeRest * tastinessStop[index];
			previousPosition = positionStop[index];
		}
	}
	std::cout << result;
	return 0;
}