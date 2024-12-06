#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numPatch, numCowNhoj, numCowJohn;
	std::cin >> numPatch >> numCowNhoj >> numCowJohn;
	std::vector<std::pair<int, int>> patches(numPatch + numCowNhoj); // include Nhoj's cow
	for (int index = 0; index < numPatch; index++) {
		std::cin >> patches[index].first >> patches[index].second;
	}
	for (int index = numPatch; index < numPatch + numCowNhoj; index++) {
		std::cin >> patches[index].first;
		patches[index].second = -1;
	}
	sort(patches.begin(), patches.end());
	std::vector<long long> increases;
	long long sumRange = 0;
	for (int rightmost = 0, lastRightmost = -1; rightmost < (int)patches.size(); rightmost++) {
		if (patches[rightmost].second == -1) {
			if (lastRightmost == -1) {
				increases.emplace_back(sumRange);
			} else {
				long long currentSum = 0, maxSum = 0;
				for (int left = lastRightmost + 1, right = lastRightmost; left < rightmost; left++) {
					while (right + 1 < rightmost && 
						(patches[right + 1].first - patches[left].first) * 2 < patches[rightmost].first - patches[lastRightmost].first) {
						right++;
						currentSum += patches[right].second;
					}
					maxSum = std::max(maxSum, currentSum);
					currentSum -= patches[left].second;
				}
				increases.emplace_back(maxSum);
				increases.emplace_back(sumRange - maxSum);
			}
			lastRightmost = rightmost;
			sumRange = 0;
		} else {
			sumRange += patches[rightmost].second;
		}
	}
	increases.emplace_back(sumRange);
	sort(increases.begin(), increases.end(), std::greater<long long>());
	long long result = 0;
	for (int index = 0; index < std::min(numCowJohn, (int)increases.size()); index++) {
		result += increases[index];
	}
	std::cout << result;
	return 0;
}