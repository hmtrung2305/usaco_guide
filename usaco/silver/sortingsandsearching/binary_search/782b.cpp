#include <bits/stdc++.h>

const double MAX_ERROR = 1e-7;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numFriend;
	std::cin >> numFriend;
	std::vector<double> location(numFriend);
	double low = 0, high = 0;
	for (double &loc : location) {
		std::cin >> loc;
		high = std::max(high, loc);
	}
	std::vector<double> speed(numFriend);
	for (double &spe : speed) {
		std::cin >> spe;
	}
	double result = 2e9;
	while (high - low > MAX_ERROR) {
		double middle = (low + high) / 2;
		double maxTime = 0;
		bool leftHasMax = false, rightHasMax = false;
		for (int index = 0; index < numFriend; index++) {
			if (location[index] == middle) {
				continue;
			}
			double time = abs(location[index] - middle) / speed[index];
			if (time > maxTime) {
				leftHasMax = false;
				rightHasMax = false;
				if (location[index] > middle) {
					rightHasMax = true;
				} else {
					leftHasMax = true;
				}
				maxTime = time;
			} else if (time == maxTime) {
				if (location[index] > middle) {
					rightHasMax = true;
				} else {
					leftHasMax = true;
				}
			}
		}
		result = std::min(result, maxTime);
		if (leftHasMax && rightHasMax) {
			break;
		} else if (leftHasMax) {
			high = middle;
		} else {
			low = middle;
		}
	}
	std::cout << std::fixed << std::setprecision(6) << result;
	return 0;
}