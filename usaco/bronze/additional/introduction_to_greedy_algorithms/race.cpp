#include <bits/stdc++.h>

int main() {
	freopen("race.in", "r", stdin);
	freopen("race.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int distance, numQuery;
	std::cin >> distance >> numQuery;
	while (numQuery--) {
		int maxSpeed;
		std::cin >> maxSpeed;
		int speedUpDistance = 0, slowDownDistance = 0, time = 0;
		for (int currentSpeed = 1; ; currentSpeed++) {
			speedUpDistance += currentSpeed;
			time++;
			if (speedUpDistance + slowDownDistance >= distance) {
				break;
			}
			if (currentSpeed >= maxSpeed) {
				slowDownDistance += currentSpeed;
				time++;
				if (speedUpDistance + slowDownDistance >= distance) {
					break;
				}
			}
		}
		std::cout << time << '\n';
	}
	return 0;
}