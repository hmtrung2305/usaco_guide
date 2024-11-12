#include <bits/stdc++.h>

const int LENGTH = 100;

int main() {
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int positionA, positionB;
	std::cin >> positionA >> positionB;
	int positionC, positionD;
	std::cin >> positionC >> positionD;
	std::vector<bool> covered(LENGTH + 1);
	for (int position = positionA; position < positionB; position++) {
		covered[position] = true;
	}
	for (int position = positionC; position < positionD; position++) {
		covered[position] = true;
	}
	int result = 0;
	for (const bool &isCover : covered) {
		result += isCover;
	}
	std::cout << result;
	return 0;
}