#include <bits/stdc++.h>

int main() {
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTypeCow;
	std::cin >> numTypeCow;
	std::vector<std::pair<int, int>> typeCow(numTypeCow);
	for (auto &[numCowType, amountMilk] : typeCow) {
		std::cin >> numCowType >> amountMilk;
	}
	sort(typeCow.begin(), typeCow.end(), [](const std::pair<int, int> &typeCow1, const std::pair<int,int> &typeCow2) {
		return typeCow1.second < typeCow2.second;
	});
	int result = 0;
	for (int left = 0, right = numTypeCow - 1; left <= right; ) {
		result = std::max(result, typeCow[left].second + typeCow[right].second);
		if (typeCow[left].first < typeCow[right].first) {
			typeCow[right].first -= typeCow[left].first;
			left++;
		} else if (typeCow[left].first > typeCow[right].first) {
			typeCow[left].first -= typeCow[right].first;
			right--;
		} else {
			left++;
			right--;
		}
	}
	std::cout << result;
	return 0;
}