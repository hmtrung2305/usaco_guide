#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthTargetStick, numStick;
	std::cin >> lengthTargetStick >> numStick;
	std::priority_queue<int, std::vector<int>, std::greater<int>> heapMin;
	for (int index = 0; index < numStick; index++) {
		int lengthStick;
		std::cin >> lengthStick;
		heapMin.emplace(lengthStick);
	}
	long long result = 0;
	for (int index = 1; index < numStick; index++) {
		int lengthStick1 = heapMin.top();
		heapMin.pop();
		int lengthStick2 = heapMin.top();
		heapMin.pop();
		heapMin.emplace(lengthStick1 + lengthStick2);
		result += lengthStick1 + lengthStick2;
	}
	std::cout << result << '\n';
	return 0;
}