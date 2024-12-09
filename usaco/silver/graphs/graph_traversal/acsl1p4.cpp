#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numPlayer, numGame;
	std::cin >> numPlayer >> numGame;
	std::vector<std::vector<int>> adjacent(numPlayer);
	while (numGame--) {
		int player1, player2, scorePlayer1, scorePlayer2;
		std::cin >> player1 >> player2 >> scorePlayer1 >> scorePlayer2;
		player1--; player2--;
		if (scorePlayer1 > scorePlayer2) {
			adjacent[player2].emplace_back(player1);
		} else {
			adjacent[player1].emplace_back(player2);
		}
	}
	std::vector<int> cyclic(numPlayer);
	std::vector<int> visited;
	int originalPlayer = 0;
	std::function<void(int)> depthFirstSearch = [&](int currentPlayer) {
		visited[currentPlayer] = true;
		if (currentPlayer == originalPlayer) {
			cyclic[currentPlayer] = true;
			return;
		}
		for (const int &nextPlayer : adjacent[currentPlayer]) {
			if (!visited[nextPlayer]) {
				depthFirstSearch(nextPlayer);
			}
		}
	};
	for (int player = 0; player < numPlayer; player++) {
		originalPlayer = player;
		visited.assign(numPlayer, false);
		for (const int &playerWin : adjacent[player]) {
			depthFirstSearch(playerWin);
		}
	}
	int result = 0;
	for (int player = 0; player < numPlayer; player++) {
		result += (cyclic[player]);
	}
	std::cout << result;
	return 0;
}