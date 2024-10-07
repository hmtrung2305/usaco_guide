#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numStick;
	std::cin >> numStick;
	std::vector<int> lengthStick(numStick);
	for (int &length : lengthStick) {
		std::cin >> length;
	}
	sort(lengthStick.begin(), lengthStick.end());
	long long result = 0;
	for (int index = 0; index < numStick; index++) {
		result += abs(lengthStick[index] - lengthStick[numStick >> 1]);
	}
	std::cout << result;
	return 0;
}