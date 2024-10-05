#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numUpdate, numQuery;
	std::cin >> numUpdate >> numQuery;
	std::vector<std::pair<int, int>> updates;
	std::vector<int> indexes;
	for (int index = 0; index < numUpdate; index++) {
		int left, right, value;
		std::cin >> left >> right >> value;
		updates.emplace_back(left, value);
		updates.emplace_back(right, -value);
		indexes.emplace_back(left);
		indexes.emplace_back(right);
	}
	std::vector<std::pair<int, int>> queries;
	for (int index = 0; index < numQuery; index++) {
		int left, right;
		std::cin >> left >> right;
		queries.emplace_back(left, right);
		indexes.emplace_back(left);
		indexes.emplace_back(right);
	}
	sort(indexes.begin(), indexes.end());
	indexes.erase(unique(indexes.begin(), indexes.end()), indexes.end());
	std::function<int(int)> newIndex = [&](int index) {
		return lower_bound(indexes.begin(), indexes.end(), index) - indexes.begin();
	};
	std::vector<long long> diff((int)indexes.size() + 1);
	for (auto [index, value] : updates) {
		diff[newIndex(index) + 1] += value;
	}
	for (int index = 1; index <= (int)indexes.size(); index++) {
		diff[index] += diff[index - 1];
	}
	std::vector<long long> prefixSum((int)indexes.size() + 1);
	for (int index = 1; index <= (int)indexes.size(); index++) {
		prefixSum[index] = prefixSum[index - 1] + diff[index] * (indexes[index] - indexes[index - 1]);
	}
	for (auto [left, right] : queries) {
		std::cout << prefixSum[newIndex(right)] - prefixSum[newIndex(left)] << '\n';
	}
	return 0;
}