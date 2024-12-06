#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numBoy, numGirl;
	std::cin >> numBoy >> numGirl;
	std::vector<int> minBoyGift(numBoy);
	long long result = 0;
	for (int &gift : minBoyGift) {
		std::cin >> gift;
		result += gift;
	}
	std::vector<int> maxGirlReceive(numGirl);
	for (int &receive : maxGirlReceive) {
		std::cin >> receive;
	}
	sort(minBoyGift.begin(), minBoyGift.end());
	sort(maxGirlReceive.begin(), maxGirlReceive.end());
	if (minBoyGift[numBoy - 1] > maxGirlReceive[0]) {
		std::cout << -1;
		return 0;
	}
	result *= numGirl;
	for (int index = 1; index < numGirl; index++) {
		result += maxGirlReceive[index] - minBoyGift[numBoy - 1];
	}
	if (maxGirlReceive[0] != minBoyGift[numBoy - 1]) {
		result += maxGirlReceive[0] - minBoyGift[numBoy - 2];
	}
	std::cout << result;
	return 0;
}