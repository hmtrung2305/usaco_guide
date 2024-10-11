#include <bits/stdc++.h>

int main() {
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCard;
	std::cin >> numCard;
	std::vector<int> cardElsie(numCard);
	std::vector<bool> hasCard(2 * numCard);
	for (int &card : cardElsie) {
		std::cin >> card;
		card--;
		hasCard[card] = true;
	}
	std::set<int> setCardBessie;
	for (int card = 0; card < 2 * numCard; card++) {
		if (!hasCard[card]) {
			setCardBessie.insert(card);
		}
	}
	int maxWin = 0;
	for (const int &card : cardElsie) {
		auto iterator = setCardBessie.upper_bound(card);
		if (iterator != setCardBessie.end()) {
			maxWin++;
			setCardBessie.erase(iterator);
		}
	}
	std::cout << maxWin;
	return 0;
}