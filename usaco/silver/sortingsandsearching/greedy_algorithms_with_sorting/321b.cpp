#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCardJiro, numCardCiel;
	std::cin >> numCardJiro >> numCardCiel;
	std::vector<std::pair<int, int>> cardJiro;
	for (int index = 0; index < numCardJiro; index++) {
		std::string type;
		int strength;
		std::cin >> type >> strength;
		cardJiro.emplace_back(type == "ATK", strength);
	}
	std::vector<std::pair<int, int>> cardCiel;
	for (int index = 0; index < numCardCiel; index++) {
		int strength;
		std::cin >> strength;
		cardCiel.emplace_back(1, strength);
	}
	sort(cardJiro.begin(), cardJiro.end(), [](const std::pair<int, int> &leftSide, const std::pair<int, int> &rightSide) {
		if (leftSide.first == rightSide.first) {
			return leftSide.second < rightSide.second;
		}
		return leftSide.first > rightSide.first;
	});
	sort(cardCiel.begin(), cardCiel.end(), [](const std::pair<int, int> &leftSide, const std::pair<int, int> &rightSide) {
		return leftSide.second > rightSide.second;
	});
	// Approach 1: maximum amount of damage without defeating all of Jiro's cards
	int resultApproach1 = 0;
	for (int index = 0; index < std::min(numCardJiro, numCardCiel); index++) {
		if (cardJiro[index].first == 0 || cardCiel[index].second <= cardJiro[index].second) {
			break;
		}
		resultApproach1 += cardCiel[index].second - cardJiro[index].second;
	}
	// Approach 2: defeating all of Jiro's cards and then deal direct damage
	reverse(cardJiro.begin(), cardJiro.end());
	reverse(cardCiel.begin(), cardCiel.end());
	int resultApproach2 = 0;
	std::vector<bool> usedCard(numCardCiel);
	for (int indexCardJiro = 0; indexCardJiro < numCardJiro; indexCardJiro++) {
		bool canDefeated = false;
		for (int indexCardCiel = 0; indexCardCiel < numCardCiel; indexCardCiel++) {
			if (!usedCard[indexCardCiel] && 
				((cardJiro[indexCardJiro].first == 1 && cardCiel[indexCardCiel].second >= cardJiro[indexCardJiro].second) ||
				(cardJiro[indexCardJiro].first == 0 && cardCiel[indexCardCiel].second > cardJiro[indexCardJiro].second))) {
				canDefeated = true;
				usedCard[indexCardCiel] = true;
				if (cardJiro[indexCardJiro].first == 1) {
					resultApproach2 += cardCiel[indexCardCiel].second - cardJiro[indexCardJiro].second;
				}
				break;
			}
		}
		if (!canDefeated) {
			std::cout << resultApproach1;
			return 0;
		}
	}
	for (int index = 0; index < numCardCiel; index++) {
		if (!usedCard[index]) {
			resultApproach2 += cardCiel[index].second;
		}
	}
	std::cout << std::max(resultApproach1, resultApproach2);
	return 0;
}