#include <bits/stdc++.h>

struct Cow {
	int weight;
	int position;
	int speed;
};

int main() {
	freopen("meetings.in", "r", stdin);
	freopen("meetings.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow, positionBarn;
	std::cin >> numCow >> positionBarn;
	std::vector<Cow> cows(numCow);
	int totalWeight = 0;
	for (Cow &cow : cows) {
		std::cin >> cow.weight >> cow.position >> cow.speed;
		totalWeight += cow.weight;
	}
	sort(cows.begin(), cows.end(), [](const Cow &cow1, const Cow &cow2) {
		return cow1.position < cow2.position;
	});
	std::vector<Cow> left;
	std::vector<Cow> right;
	for (const Cow &cow : cows) {
		if (cow.speed == -1) {
			left.emplace_back(cow);
		} else {
			right.emplace_back(cow);
		}
	}
	std::vector<std::pair<int, int>> timeWeight;
	for (int index = 0; index < (int)left.size(); index++) {
		timeWeight.emplace_back(left[index].position, cows[index].weight);
	}
	for (int index = 0; index < (int)right.size(); index++) {
		timeWeight.emplace_back(positionBarn - right[index].position, cows[(int)left.size() + index].weight);
	}
	sort(timeWeight.begin(), timeWeight.end(), [](const std::pair<int, int> &time1, const std::pair<int, int> &time2) {
		return time1.first < time2.first;
	});
	int endTime = -1;
	for (const auto &[time, weight] : timeWeight) {
		totalWeight -= 2 * weight;
		if (totalWeight <= 0) {
			endTime = time;
			break;
		}
	}
	int countMeeting = 0;
	std::queue<int> queueLeft;
	for (int index = 0; index < numCow; index++) {
		if (cows[index].speed == 1) {
			queueLeft.emplace(cows[index].position);
		} else {
			while (!queueLeft.empty() && queueLeft.front() + 2 * endTime < cows[index].position) {
				queueLeft.pop();
			}
			countMeeting += (int)queueLeft.size();
		}
	}
	std::cout << countMeeting;
	return 0;
}