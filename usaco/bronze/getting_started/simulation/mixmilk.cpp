#include <bits/stdc++.h>

int main() {
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::vector<int> capacityBucket(3), amountBucket(3);
	for (int bucket = 0; bucket < 3; bucket++) {
		std::cin >> capacityBucket[bucket] >> amountBucket[bucket];
	}
	for (int step = 0; step < 100; step++) {
		int bucket1 = step % 3;
		int bucket2 = (step + 1) % 3;
		int amountPour = std::min(amountBucket[bucket1], capacityBucket[bucket2] - amountBucket[bucket2]);
		amountBucket[bucket1] -= amountPour;
		amountBucket[bucket2] += amountPour;
	}
	for (int &amount : amountBucket) {
		std::cout << amount << '\n';
	}
	return 0;
}