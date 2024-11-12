#include <bits/stdc++.h>

int main() {
	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int positionJohn, positionBessie;
	std::cin >> positionJohn >> positionBessie;
	positionBessie -= positionJohn;
	int distance = abs(positionBessie);
	int timeSwap = ceil(log(distance) / log(2));
	timeSwap += (timeSwap + (positionBessie < 0)) % 2;
	std::cout << 2 * (pow(2, timeSwap) - 1) + distance;
	return 0;
}