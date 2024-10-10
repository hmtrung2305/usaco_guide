#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthArr;
	std::cin >> lengthArr;
	std::vector<int> arr(lengthArr);
	for (int &num : arr) {
		std::cin >> num;
	}
	std::vector<int> suffixGCD(lengthArr);
	suffixGCD[lengthArr - 1] = arr[lengthArr - 1];
	for (int index = lengthArr - 2; index >= 0; index--) {
		suffixGCD[index] = std::__gcd(suffixGCD[index + 1], arr[index]);
	}
	int result = suffixGCD[1];
	int prefixGcd = 0;
	for (int index = 0; index + 1 < lengthArr; index++) {
		result = std::max(result, std::__gcd(prefixGcd, suffixGCD[index + 1]));
		prefixGcd = std::__gcd(prefixGcd, arr[index]);
	}
	result = std::max(result, prefixGcd);
	std::cout << result;
	return 0;
}