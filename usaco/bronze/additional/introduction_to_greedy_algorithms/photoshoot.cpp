#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	std::string position;
	std::cin >> position;
	int countFlip = 0;
	for (int index = numCow - 2; index >= 0; index -= 2) {
		std::string pair = position.substr(index, 2);
		if ((pair == "GH" && countFlip % 2 == 0) || (pair == "HG" && countFlip % 2 == 1)) {
			countFlip++;
		}
	}
	std::cout << countFlip;
	return 0;
}