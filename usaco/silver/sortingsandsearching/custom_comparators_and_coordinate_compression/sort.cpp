#include <bits/stdc++.h>

int main() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthArr;
	std::cin >> lengthArr;
	std::vector<std::pair<int, int>> arr(lengthArr);
	for (int index = 0; index < lengthArr; index++) {
		std::cin >> arr[index].first;
		arr[index].second = index;
	}
	sort(arr.begin(), arr.end());
	int result = 0;
	for (int index = 0; index < lengthArr; index++) {
		result = std::max(result, arr[index].second - index + 1);
	}
	std::cout << result;
	return 0;
}