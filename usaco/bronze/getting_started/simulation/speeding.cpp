#include <bits/stdc++.h>

int main() {
	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numRoad, numJourney;
	std::cin >> numRoad >> numJourney;
	std::vector<std::pair<int, int>> roads(numRoad);
	for (auto &[length, limitSpeed] : roads) {
		std::cin >> length >> limitSpeed;
	}
	std::vector<std::pair<int, int>> journeys(numJourney);
	for (auto &[length, speed] : journeys) {
		std::cin >> length >> speed;
	}
	int lengthRoad = 0, lengthJourney = 0;
	int result = 0;
	for (int road = 0, journey = 0; road < numRoad; road++) {
		lengthRoad += roads[road].first;
		if (lengthJourney >= lengthRoad) {
			result = std::max(result, journeys[journey - 1].second - roads[road].second);
		}
		while (journey < numJourney && lengthRoad > lengthJourney) {
			result = std::max(result, journeys[journey].second - roads[road].second);
			lengthJourney += journeys[journey].first;
			journey++;
		}
	}
	std::cout << result;
	return 0;
}