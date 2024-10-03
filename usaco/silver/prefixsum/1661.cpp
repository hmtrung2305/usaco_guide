#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthArr, target;
	std::cin >> lengthArr >> target;
	std::map<long long, long long> count;
	long long result = 0;
	long long currentSum = 0;
	for (int index = 0; index < lengthArr; index++) {
		count[currentSum]++;
		int num;
		std::cin >> num;
		currentSum += num;
		result += count[currentSum - target];
	}
	std::cout << result;
	return 0;
}