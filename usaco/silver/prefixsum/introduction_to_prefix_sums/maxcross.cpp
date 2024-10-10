#include <bits/stdc++.h>

int main() {
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCrosswalk, target, numSignal;
	std::cin >> numCrosswalk >> target >> numSignal;
	std::vector<int> prefixSum(numCrosswalk);
	for (int index = 0; index < numSignal; index++) {
		int signal;
		std::cin >> signal;
		signal--;
		prefixSum[signal]++;
	}
	int result = 1e9;
	for (int index = 1; index < numCrosswalk; index++) {
		prefixSum[index] += prefixSum[index - 1];
	}
	for (int index = 0; index < numCrosswalk - target; index++) {
		result = std::min(result, prefixSum[index + target] - prefixSum[index]);
	}
	std::cout << result;
	return 0;
}