#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numFlower;
	std::cin >> numFlower;
	std::vector<int> flower(numFlower);
	for (int &petal : flower) {
		std::cin >> petal;
	}
	int result = 0;
	for (int left = 0; left < numFlower; left++) {	
		double sum = 0;
		for (int right = left; right < numFlower; right++) {
			sum += flower[right];
			double average = sum / (right - left + 1);
			for (int index = left; index <= right; index++) {
				if (flower[index] == average) {
					result++;
					break;
				}
			}
		}
	}
	std::cout << result;
	return 0;
}