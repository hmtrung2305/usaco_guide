#include <bits/stdc++.h>

int main() {
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numDiamond, limitDiffer;
	std::cin >> numDiamond >> limitDiffer;
	std::vector<int> sizeDiamond(numDiamond);
	for (int &size : sizeDiamond) {
		std::cin >> size;
	}
	int result = 0;
	for (int index = 0; index < numDiamond; index++) {
		int count = 0;
		for (const int &size : sizeDiamond) {
			if (sizeDiamond[index] <= size && size <= sizeDiamond[index] + limitDiffer) {
				count++;
			}
		}
		result = std::max(result, count);
	}
	std::cout << result;
	return 0;
}