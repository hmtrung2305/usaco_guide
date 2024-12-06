#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::string bitStr;
	std::cin >> bitStr;
	std::set<int> setPosition{0, (int)bitStr.size()};
	for (int index = 0; index < (int)bitStr.size() - 1; index++) {
		if (bitStr[index + 1] != bitStr[index]) {
			setPosition.insert(index + 1);
		}
	}
	std::multiset<int> setDiff;
	for (std::set<int>::iterator iterator = setPosition.begin(); next(iterator) != setPosition.end(); iterator++) {
		setDiff.insert(*next(iterator) - *iterator);
	}
	std::function<void(int)> modify = [&](int position) {
		if (position == 0 || position == (int)bitStr.size()) {
			return;
		}
		std::set<int>::iterator iterator = setPosition.find(position);
		if (iterator != setPosition.end()) {
			int left = *prev(iterator);
			int right = *next(iterator);
			setDiff.erase(setDiff.find(position - left));
			setDiff.erase(setDiff.find(right - position));
			setDiff.insert(right - left);
			setPosition.erase(iterator);
		} else {
			setPosition.insert(position);
			iterator = setPosition.find(position);
			int left = *prev(iterator);
			int right = *next(iterator);
			setDiff.erase(setDiff.find(right - left));
			setDiff.insert(position - left);
			setDiff.insert(right - position);
		}
	};
	int numChange;
	std::cin >> numChange;
	while (numChange--) {
		int positionChange;
		std::cin >> positionChange;
		modify(positionChange - 1);
		modify(positionChange);
		std::cout << *setDiff.rbegin() << ' ';
	}
	return 0;
}