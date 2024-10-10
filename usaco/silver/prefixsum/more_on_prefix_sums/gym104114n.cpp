#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numSlice, limitDiff;
	std::cin >> numSlice >> limitDiff;
	std::vector<int> saltiness(numSlice);
	for (int &slice : saltiness) {
		std::cin >> slice;
	}
	for (int slice = 1; slice < numSlice; slice++) {
		if (saltiness[slice] < saltiness[slice - 1] - limitDiff) {
			saltiness[slice] = saltiness[slice - 1] - limitDiff;
		}
	}
	for (int slice = numSlice - 2; slice >= 0; slice--) {
		if (saltiness[slice] < saltiness[slice + 1] - limitDiff) {
			saltiness[slice] = saltiness[slice + 1] - limitDiff;
		}
	}
	for (int slice : saltiness) {
		std::cout << slice << ' ';
	}
	return 0;
}