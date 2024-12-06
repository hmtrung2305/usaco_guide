#include <bits/stdc++.h>

int main() {
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numHalfCard;
	std::cin >> numHalfCard;
	std::vector<bool> hasCard(2 * numHalfCard);
	std::vector<int> cardElsie(numHalfCard);
	for (int index = 0; index < numHalfCard; index++) {
		std::cin >> cardElsie[index];
		cardElsie[index]--;
		hasCard[cardElsie[index]] = true;
	}
	sort(cardElsie.begin(), cardElsie.begin() + numHalfCard / 2);
	sort(cardElsie.begin() + numHalfCard / 2, cardElsie.end());
	rotate(cardElsie.begin(), cardElsie.begin() + numHalfCard / 2, cardElsie.end());
	std::vector<int> cardBessie;
	for (int card = 0; card < 2 * numHalfCard; card++) {
		if (!hasCard[card]) {
			cardBessie.emplace_back(card);
		}
	}
	int result = 0;
	for (int indexCardElsie = numHalfCard / 2, indexCardBessie = numHalfCard / 2; indexCardElsie < numHalfCard; indexCardElsie++, indexCardBessie++) {
		while (indexCardBessie < numHalfCard && cardBessie[indexCardBessie] < cardElsie[indexCardElsie]) {
			indexCardBessie++;
		}
		if (indexCardBessie == numHalfCard) {
			break;
		}
		result++;
	}
	for (int indexCardElsie = numHalfCard / 2 - 1, indexCardBessie = numHalfCard / 2 - 1; indexCardElsie >= 0; indexCardElsie--, indexCardBessie--) {
		while (indexCardBessie < numHalfCard && cardBessie[indexCardBessie] > cardElsie[indexCardElsie]) {
			indexCardBessie--;
		}
		if (indexCardBessie == -1) {
			break;
		}
		result++;
	}
	std::cout << result;
	return 0;
}