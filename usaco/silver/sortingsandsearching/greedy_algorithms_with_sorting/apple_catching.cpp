#include <bits/stdc++.h>

struct Object {
	int type, time, location, amount;
};

int main() {
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(0);
	int numTime;
	std::cin >> numTime;
	std::vector<Object> objects(numTime);
	for (auto &[type, time, location, amount] : objects) {
		std::cin >> type >> time >> location >> amount;
	}
	sort(objects.begin(), objects.end(), [](const Object &leftSide, const Object &rightSide) {
		if (leftSide.location - leftSide.time == rightSide.location - rightSide.time) {
			return leftSide.type > rightSide.type;
		}
		return leftSide.location - leftSide.time < rightSide.location - rightSide.time;
	});
	int result = 0;
	std::map<int, int> amountApple;
	for (const auto &[type, time, location, amount] : objects) {
		if (type == 2) {
			amountApple[location + time] += amount;
		} else {
			int current = amount;
			while (current) {
				auto iterator = amountApple.lower_bound(location + time);
				if (iterator == amountApple.end()) {
					break;
				}
				int findAmount = std::min(amount, iterator->second);
				if (findAmount == iterator->second) {
					amountApple.erase(iterator);
				} else {
					iterator->second -= findAmount;
				}
				current -= findAmount;
				result += findAmount;
			}
		}
	}
	std::cout << result;
	return 0;
}