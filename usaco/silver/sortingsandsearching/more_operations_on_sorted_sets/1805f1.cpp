/*
practicing..
can n^2.. hmmm
*/
#include <bits/stdc++.h>

const int MODULO = 1e9 + 7;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthArr;
	std::cin >> lengthArr;
	std::vector<long long> arr(lengthArr);
	for (long long &num : arr) {
		std::cin >> num;
	}
	sort(arr.begin(), arr.end());
	for (int size = lengthArr - 1; size >= 1; size--) {
		std::vector<long long> nextArr;
		std::priority_queue<std::array<long long, 3>, std::vector<std::array<long long, 3>>, std::greater<std::array<long long, 3>>> minHeap;
		for (int index = 0; index < size; index++) {
			minHeap.push({arr[index] + arr[index + 1], index, index + 1});
		}
		for (int index = 0; index < size; index++) {
			auto [sum, left, right] = minHeap.top();
			minHeap.pop();
			nextArr.emplace_back(sum);
			if (right + 1 < (int)arr.size()) {
				minHeap.push({arr[left] + arr[right + 1], left, right + 1});
			}
		}
		// remainder of nextArr[0] 
		long long remainder = nextArr[0] / MODULO;
		for (int index = 0; index < size; index++) {
			nextArr[index] -= remainder * MODULO;
		}
		arr = nextArr;
	}
	std::cout << arr[0];
	return 0;
}