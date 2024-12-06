#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int numFriend;
		long long timeCookie, timeMuffin;
		std::cin >> numFriend >> timeCookie >> timeMuffin;
		std::vector<long long> cookieFriend(numFriend), muffinFriend(numFriend), limitTime(numFriend);
		for (int index = 0; index < numFriend; index++) {
			std::cin >> cookieFriend[index] >> muffinFriend[index] >> limitTime[index];
		}
		long long low = 0, high = timeCookie + timeMuffin - 2;
		long long result = high;
		while (low <= high) {
			long long middle = low + ((high - low + 1) >> 1);
			long long base = timeCookie + timeMuffin - middle;
			long long minTimeCookie = std::max(1ll, timeCookie - middle);
			long long maxTimeCookie = std::min(timeCookie, timeCookie + timeMuffin - middle - 1);
			bool satisfyCondition = true;
			for (int index = 0; index < numFriend; index++) {
				if (muffinFriend[index] - cookieFriend[index] > 0) {
					minTimeCookie = std::max(minTimeCookie, (-limitTime[index] + muffinFriend[index] * base + (muffinFriend[index] - cookieFriend[index] - 1)) / (muffinFriend[index] - cookieFriend[index]));
				} else if (muffinFriend[index] - cookieFriend[index] < 0) {
					maxTimeCookie = std::min(maxTimeCookie, (limitTime[index] - muffinFriend[index] * base) / (cookieFriend[index] - muffinFriend[index]));
				} else {
					if (muffinFriend[index] * base > limitTime[index]) {
						satisfyCondition = false;
					}
				}
			}
			if (satisfyCondition && minTimeCookie <= maxTimeCookie) {
				result = middle;
				high = middle - 1;
			} else {
				low = middle + 1;
			}
		}
		std::cout << result << '\n';
	}
	return 0;
}

/* Editorial:

1. 1 <= needTimeCookie <= timeCookie
2. 1 <= needTimeMuffin <= timeMuffin
3. cookieFriend[friend] * needTimeCookie + muffinFriend[friend] * needTimeMuffin <= limitTime[friend]

Binary Search -> middle

(1, 2)
-> needTimeCookie + needTimeMuffin = timeCookie + timeMuffin - middle 
-> needTimeMuffin = timeCookie + timeMuffin - middle - needTimeCookie (4)

(3)
-> cookieFriend[friend] * needTimeCookie + muffinFriend[friend] * needTimeMuffin <= limitTime[friend]
-> cookieFriend[friend] * needTimeCookie <= limitTime[friend] - muffinFriend[friend] * needTimeMuffin
(4)
-> cookieFriend[friend] * needTimeCookie <= limitTime[friend] - muffinFriend[friend] * (timeCookie + timeMuffin - middle - needTimeCookie)
-> cookieFriend[friend] * needTimeCookie <= limitTime[friend] - muffinFriend[friend] * (timeCookie + timeMuffin - middle) + muffinFriend[friend] * needTimeCookie
-> cookieFriend[friend] * needTimeCookie - muffinFriend[friend] * needTimeCookie <= limitTime[friend] - muffinFriend[friend] * (timeCookie + timeMuffin - middle)
-> needTimeCookie - (cookieFriend[friend] - muffinFriend[friend]) <= limitTime[friend] - muffinFriend[friend] * (timeCookie + timeMuffin - middle)

*/