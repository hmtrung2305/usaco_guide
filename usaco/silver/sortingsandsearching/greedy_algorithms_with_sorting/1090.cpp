#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numChildren, maxWeight;
	std::cin >> numChildren >> maxWeight;
	std::vector<int> weightChild(numChildren);
	for (int &weight : weightChild) {
		std::cin >> weight;
	}
	sort(weightChild.begin(), weightChild.end());
	int countPair = 0;
	for (int left = 0, right = numChildren - 1; left < right; ) {
		while (left < right && weightChild[left] + weightChild[right] > maxWeight) {
			right--;
		}
		if (left == right) {
			break;
		}
		countPair++;
		left++;
		right--;
	}
	std::cout << numChildren - countPair;
	return 0;
}