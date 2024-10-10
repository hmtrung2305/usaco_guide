#include <bits/stdc++.h>

int main() {
	freopen("stacking.in", "r", stdin);
	freopen("stacking.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numStack, instructions;
	std::cin >> numStack >> instructions;
	std::vector<int> prefixSum(numStack + 1);
	for (int index = 0; index < instructions; index++) {
		int left, right;
		std::cin >> left >> right;
		prefixSum[left]++;
		if (right < numStack) {
			prefixSum[right + 1]--;
		}
	}
	for (int index = 1; index <= numStack; index++) {
		prefixSum[index] += prefixSum[index - 1];
	}
	sort(prefixSum.begin(), prefixSum.end());
	std::cout << prefixSum[numStack / 2 + 1];
	return 0;
}