#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numPeople;
	std::cin >> numPeople;
	numPeople *= 2;
	std::vector<int> weightPeople(numPeople);
	for (int &weight : weightPeople) {
		std::cin >> weight;
	}
	sort(weightPeople.begin(), weightPeople.end());
	int minInstability = 1e9;
	for (int removePeople1 = 0; removePeople1 < numPeople; removePeople1++) {
		for (int removePeople2 = removePeople1 + 1; removePeople2 < numPeople; removePeople2++) {
			std::vector<int> weightPeoplePair;
			for (int index = 0; index < numPeople; index++) {
				if (index != removePeople1 && index != removePeople2) {
					weightPeoplePair.emplace_back(weightPeople[index]);
				}
			}
			int totalInstability = 0;
			for (int index = 0; index < numPeople - 2; index += 2) {
				totalInstability += weightPeoplePair[index + 1] - weightPeoplePair[index];
			}
			minInstability = std::min(minInstability, totalInstability);
		}
	}
	std::cout << minInstability;
	return 0;
}