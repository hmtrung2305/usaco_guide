#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCity, numTower;
	std::cin >> numCity >> numTower;
	std::vector<int> positionCity(numCity);
	for (int &position : positionCity) {
		std::cin >> position;
	}
	std::vector<int> positionTower(numTower);
	for (int &position : positionTower) {
		std::cin >> position;
	}
	std::vector<int> distance(numCity, 2e9);
	for (int indexCity = 0, indexTower = 0; indexCity < numCity; indexCity++) {
		while (indexTower + 1 < numTower && positionTower[indexTower + 1] <= positionCity[indexCity]) {
			indexTower++;
		}
		distance[indexCity] = std::min(distance[indexCity], abs(positionCity[indexCity] - positionTower[indexTower]));
	}
	for (int indexCity = numCity - 1, indexTower = numTower - 1; indexCity >= 0; indexCity--) {
		while (indexTower > 0 && positionTower[indexTower - 1] >= positionCity[indexCity]) {
			indexTower--;
		}
		distance[indexCity] = std::min(distance[indexCity], abs(positionCity[indexCity] - positionTower[indexTower]));
	}
	int result = 0;
	for (int index = 0; index < numCity; index++) {
		result = std::max(result, distance[index]);
	}
	std::cout << result;
	return 0;
}