/*
practicing - but sickness..
*/
#include <bits/stdc++.h>

const int BOX = 1e9;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int numBall;
		std::cin >> numBall;
		std::map<int, std::vector<int>> rightBoxInLeftBox;
		std::set<int> setLeftBox;
		for (int index = 0; index < numBall; index++) {
			int leftBox, rightBox;
			std::cin >> leftBox >> rightBox;
			rightBoxInLeftBox[leftBox].emplace_back(rightBox);
			setLeftBox.insert(leftBox);
		}
		setLeftBox.insert(BOX + 1);
		std::priority_queue<int, std::vector<int>, std::greater<int>> currentMinBox;
		bool satisfyCondition = true;
		int box = *setLeftBox.begin();
		while (box <= BOX) {
			for (const int &rightBox : rightBoxInLeftBox[box]) {
				currentMinBox.emplace(rightBox);
			}
			currentMinBox.pop();
			if (currentMinBox.empty()) {
				box = *setLeftBox.lower_bound(box + 1);
			} else {
				if (currentMinBox.top() <= box) {
					satisfyCondition = false;
					break;
				}
				box++;
			}
		}
		std::cout << (satisfyCondition ? "YES" : "NO") << '\n';
	}
	return 0;
}