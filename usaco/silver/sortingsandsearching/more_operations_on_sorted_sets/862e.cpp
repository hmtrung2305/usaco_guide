#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthAlpha, lengthBeta, numQuery;
	std::cin >> lengthAlpha >> lengthBeta >> numQuery;
	std::vector<int> alpha(lengthAlpha);
	for (int &num : alpha) {
		std::cin >> num;
	}
	std::vector<int> beta(lengthBeta);
	for (int &num : beta) {
		std::cin >> num;
	}
	std::vector<long long> prefixSumOddBeta(lengthBeta), prefixSumEvenBeta(lengthBeta);
	for (int index = 0; index < lengthBeta; index++) {
		prefixSumOddBeta[index] = (index > 0 ? prefixSumOddBeta[index - 1] : 0) + (index & 1 ? beta[index] : 0);
		prefixSumEvenBeta[index] = (index > 0 ? prefixSumEvenBeta[index - 1] : 0) + (index & 1 ? 0 : beta[index]);
	}
	assert(lengthBeta >= lengthAlpha);
	std::vector<long long> sumBeta(lengthBeta - lengthAlpha + 1);
	for (int index = 0; index <= lengthBeta - lengthAlpha; index++) {
		long long sumOdd = prefixSumOddBeta[index + lengthAlpha - 1] - (index > 0 ? prefixSumOddBeta[index - 1] : 0);
		long long sumEven = prefixSumEvenBeta[index + lengthAlpha - 1] - (index > 0 ? prefixSumEvenBeta[index - 1] : 0);
		if (index & 1) {
			sumBeta[index] = sumOdd - sumEven;
		} else {
			sumBeta[index] = sumEven - sumOdd;
		}
	}
	sort(sumBeta.begin(), sumBeta.end());
	long long sumAlpha = 0;
	for (int index = 0; index < lengthAlpha; index++) {
		sumAlpha += ((index & 1) ? -alpha[index] : alpha[index]);
	}
	auto iterator = lower_bound(sumBeta.begin(), sumBeta.end(), sumAlpha);
	if (iterator == sumBeta.end()) {
		std::cout << abs(*(prev(iterator)) - sumAlpha) << '\n';
	} else {
		long long result = *iterator - sumAlpha;
		if (iterator != prev(sumBeta.end())) {
			result = std::min(result, abs(*(next(iterator)) - sumAlpha));
		}
		if (iterator != sumBeta.begin()) {
			result = std::min(result, abs(*(prev(iterator)) - sumAlpha));
		}
		std::cout << result << '\n';
	}
	while (numQuery--) {
		long long left, right, value;
		std::cin >> left >> right >> value;
		if ((right - left + 1) & 1) {
			if (left & 1) {
				sumAlpha += value;
			} else {
				sumAlpha -= value;
			}
		}
		iterator = lower_bound(sumBeta.begin(), sumBeta.end(), sumAlpha);
		if (iterator == sumBeta.end()) {
			std::cout << abs(*(prev(iterator)) - sumAlpha) << '\n';
		} else {
			long long result = *iterator - sumAlpha;
			if (iterator != prev(sumBeta.end())) {
				result = std::min(result, abs(*(next(iterator)) - sumAlpha));
			}
			if (iterator != sumBeta.begin()) {
				result = std::min(result, abs(*(prev(iterator)) - sumAlpha));
			}
			std::cout << result << '\n';
		}
	}
	return 0;
}