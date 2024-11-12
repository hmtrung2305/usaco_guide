#include <bits/stdc++.h>

const int TIME = 1000;

int main() {
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	std::vector<int> bucketTime(TIME);
	for (int index = 0; index < numCow; index++) {
		int start, end, needBucket;
		std::cin >> start >> end >> needBucket;
		start--; end--;
		for (int time = start; time <= end; time++) {
			bucketTime[time] += needBucket;
		}
	}
	std::cout << *max_element(bucketTime.begin(), bucketTime.end());
	return 0;
}