#include <bits/stdc++.h>

int main() {
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numDiamond, limitDiff;
	std::cin >> numDiamond >> limitDiff;
	std::vector<int> sizeDiamond(numDiamond);
	for (int &size : sizeDiamond) {
		std::cin >> size;
	}
	sort(sizeDiamond.begin(), sizeDiamond.end());
	std::vector<int> prefixMax(numDiamond);
	for (int left = 0, right = 0; right < numDiamond; right++) {
		while (left + 1 <= right && sizeDiamond[right] - sizeDiamond[left] > limitDiff) {
			left++;
		}
		prefixMax[right] = std::max(right > 0 ? prefixMax[right - 1] : 0, right - left + 1);
	}
	int result = prefixMax[numDiamond - 1];
	for (int left = numDiamond - 1, right = numDiamond - 1; left >= 0; left--) {
		while (right - 1 >= left && sizeDiamond[right] - sizeDiamond[left] > limitDiff) {
			right--;
		}
		result = std::max(result, right - left + 1 + (left > 0 ? prefixMax[left - 1] : 0));
	}
	std::cout << result;
	return 0;
}