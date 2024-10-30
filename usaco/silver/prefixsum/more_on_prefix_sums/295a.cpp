#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthArr, numOperation, numQuery;
	std::cin >> lengthArr >> numOperation >> numQuery;
	std::vector<int> arr(lengthArr);
	for (int &num : arr) {
		std::cin >> num;
	}
	std::vector<std::array<int, 3>> operations(numOperation);
	for (std::array<int, 3> &operation : operations) {
		std::cin >> operation[0] >> operation[1] >> operation[2];
	}
	std::vector<int> prefixSumOperation(numOperation + 2, 0);
	for (int index = 0; index < numQuery; index++) {
		int left, right;
		std::cin >> left >> right;
		prefixSumOperation[left]++;
		prefixSumOperation[right + 1]--;
	}
	std::vector<long long> add(lengthArr + 2, 0ll);
	for (int index = 1; index <= numOperation; index++) {
		prefixSumOperation[index] += prefixSumOperation[index - 1];
		add[operations[index - 1][0]] += 1ll * prefixSumOperation[index] * operations[index - 1][2];
		add[operations[index - 1][1] + 1] -= 1ll * prefixSumOperation[index] * operations[index - 1][2];
	}
	for (int index = 1; index <= lengthArr; index++) {
		add[index] += add[index - 1];
		std::cout << 1ll * arr[index - 1] + add[index] << ' ';
	}
	return 0;
}