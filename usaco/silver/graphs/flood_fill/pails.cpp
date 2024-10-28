#include <bits/stdc++.h>

int main() {
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int capacityPail1, capacityPail2, limitOperation, target;
	std::cin >> capacityPail1 >> capacityPail2 >> limitOperation >> target;
	std::vector<std::vector<bool>> hasCapacity(capacityPail1 + 1, std::vector<bool>(capacityPail2 + 1, false));
	hasCapacity[0][0] = true;
	std::queue<std::array<int, 3>> queue;
	queue.push({0, 0, 0});
	int result = 1e9;
	while (!queue.empty()) {
		auto [currentCapacityPail1, currentCapacityPail2, step] = queue.front();
		queue.pop();
		result = std::min(result, abs(currentCapacityPail1 + currentCapacityPail2 - target));
		if (step == limitOperation) {
			continue;
		}
		/// Operation Type 1
		int nextCapacityPail1 = capacityPail1;
		int nextCapacityPail2 = currentCapacityPail2;
		if (!hasCapacity[nextCapacityPail1][nextCapacityPail2]) {
			hasCapacity[nextCapacityPail1][nextCapacityPail2] = true;
			queue.push({nextCapacityPail1, nextCapacityPail2, step + 1});
		}
		nextCapacityPail1 = currentCapacityPail1;
		nextCapacityPail2 = capacityPail2;
		if (!hasCapacity[nextCapacityPail1][nextCapacityPail2]) {
			hasCapacity[nextCapacityPail1][nextCapacityPail2] = true;
			queue.push({nextCapacityPail1, nextCapacityPail2, step + 1});
		}
		/// Operation Type 2
		nextCapacityPail1 = 0;
		nextCapacityPail2 = currentCapacityPail2;
		if (!hasCapacity[nextCapacityPail1][nextCapacityPail2]) {
			hasCapacity[nextCapacityPail1][nextCapacityPail2] = true;
			queue.push({nextCapacityPail1, nextCapacityPail2, step + 1});
		}
		nextCapacityPail1 = currentCapacityPail1;
		nextCapacityPail2 = 0;
		if (!hasCapacity[nextCapacityPail1][nextCapacityPail2]) {
			hasCapacity[nextCapacityPail1][nextCapacityPail2] = true;
			queue.push({nextCapacityPail1, nextCapacityPail2, step + 1});
		}
		/// Operation Type 3
		// pour pail 1 into pail 2
		int amount = std::min(currentCapacityPail1, capacityPail2 - currentCapacityPail2);
		nextCapacityPail1 = currentCapacityPail1 - amount;
		nextCapacityPail2 = currentCapacityPail2 + amount;
		if (!hasCapacity[nextCapacityPail1][nextCapacityPail2]) {
			hasCapacity[nextCapacityPail1][nextCapacityPail2] = true;
			queue.push({nextCapacityPail1, nextCapacityPail2, step + 1});
		}
		// pour pail 2 into pail 1
		amount = std::min(currentCapacityPail2, capacityPail1 - currentCapacityPail1);
		nextCapacityPail1 = currentCapacityPail1 + amount;
		nextCapacityPail2 = currentCapacityPail2 - amount;
		if (!hasCapacity[nextCapacityPail1][nextCapacityPail2]) {
			hasCapacity[nextCapacityPail1][nextCapacityPail2] = true;
			queue.push({nextCapacityPail1, nextCapacityPail2, step + 1});
		}
	}
	std::cout << result;
	return 0;
}