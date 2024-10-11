#include <bits/stdc++.h>

struct Mouse {
	int cost, type;
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numComputerUSB, numComputerPS2, numComputerBoth;
	std::cin >> numComputerUSB >> numComputerPS2 >> numComputerBoth;
	int numMouse;
	std::cin >> numMouse;
	std::vector<Mouse> mouses(numMouse);
	for (auto &[cost, type] : mouses) {
		std::string typeStr;
		std::cin >> cost >> typeStr;
		type = (typeStr[0] == 'U' ? 0 : 1);
	}
	sort(mouses.begin(), mouses.end(), [](const Mouse &mouse1, const Mouse & mouse2) {
		return mouse1.cost < mouse2.cost;
	});
	int countEquipped = 0;
	long long minTotalCost = 0;
	for (const auto &[cost, type] : mouses) {
		if (type == 0 && numComputerUSB > 0) {
			numComputerUSB--;
			countEquipped++;
			minTotalCost += cost;
		} else if (type == 1 && numComputerPS2 > 0) {
			numComputerPS2--;
			countEquipped++;
			minTotalCost += cost;
		} else if (numComputerBoth > 0) {
			numComputerBoth--;
			countEquipped++;
			minTotalCost += cost;
		}
	}
	std::cout << countEquipped << ' ' << minTotalCost;
	return 0;
}