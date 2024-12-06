/*
practicing..
*/
#include <bits/stdc++.h>

int main() {
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numMeasurement, initialOutput;
	std::cin >> numMeasurement >> initialOutput;
	std::vector<std::array<int, 3>> log(numMeasurement);
	std::map<int, int> outputCow;
	for (auto &[day, idCow, change] : log) {
		std::cin >> day >> idCow >> change;
		outputCow[idCow] = initialOutput;
	}
	sort(log.begin(), log.end(), [](const std::array<int, 3> &leftSide, const std::array<int, 3> &rightSide) {
		return leftSide[0] < rightSide[0];
	});
	std::map<int, int> countCowHaveOutput;
	int changeDisplay = 0;
	countCowHaveOutput[initialOutput] = numMeasurement;
	for (const auto &[day, idCow, change] : log) {
		int amountMilk = outputCow[idCow];
		bool wasTop = amountMilk == countCowHaveOutput.rbegin()->first;
		int previousCount = countCowHaveOutput[amountMilk];
		countCowHaveOutput[amountMilk]--;
		if (countCowHaveOutput[amountMilk] == 0) {
			countCowHaveOutput.erase(amountMilk);
		}
		amountMilk += change;
		outputCow[idCow] = amountMilk;
		countCowHaveOutput[amountMilk]++;
		bool isTop = amountMilk == countCowHaveOutput.rbegin()->first;
		int currentCount = countCowHaveOutput[amountMilk];
		if (wasTop) {
			if (isTop && currentCount == previousCount) {
				continue;
			}
			changeDisplay++;
		} else if (isTop) {
			changeDisplay++;
		}
	}
	std::cout << changeDisplay;
	return 0;
}