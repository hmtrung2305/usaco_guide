#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthArr;
	std::cin >> lengthArr;
	std::unordered_map<int, int> count;
	int currentSum = 0;
	long long result = 0;
	for (int index = 0; index < lengthArr; index++) {
		count[currentSum]++;
		int num;
		std::cin >> num;
		currentSum = (currentSum + num % lengthArr + lengthArr) % lengthArr;
		result += count[currentSum];
	}
	std::cout << result;
	return 0;
}