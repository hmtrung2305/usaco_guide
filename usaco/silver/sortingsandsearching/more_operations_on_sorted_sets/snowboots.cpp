/*
practicing - but sickness..
*/
#include <bits/stdc++.h>

int main() {
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTile, numBoot;
	std::cin >> numTile >> numBoot;
	std::vector<int> heightTile(numTile);
	for (int &height : heightTile) {
		std::cin >> height;
	}
	std::vector<std::array<int, 3>> boots(numBoot);
	for (int index = 0; index < numBoot; index++) {
		std::cin >> boots[index][0] >> boots[index][1];
		boots[index][2] = index;
	}
	sort(boots.begin(), boots.end(), [](const std::array<int, 3> &leftSide, const std::array<int, 3> &rightSide) {
		return leftSide[0] > rightSide[0];
	});
	std::vector<int> indexSortedTile(numTile);
	iota(indexSortedTile.begin(), indexSortedTile.end(), 0);
	sort(indexSortedTile.begin(), indexSortedTile.end(), [&](int leftSide, int rightSide) {
		return heightTile[leftSide] > heightTile[rightSide];
	});
	std::set<int> setValidIndexTile;
	for (int index = 0; index < numTile; index++) {
		setValidIndexTile.insert(index);
	}
	std::vector<bool> bootCanReach(numBoot);
	int indexTile = 0;
	int stepNeeded = 1;
	for (const auto &[mostFeetBoot, mostStepBoot, indexBoot] : boots) {
		while (indexTile < (int)indexSortedTile.size() && heightTile[indexSortedTile[indexTile]] > mostFeetBoot) {
			auto removed = setValidIndexTile.find(indexSortedTile[indexTile]);
			stepNeeded = std::max(stepNeeded, *next(removed) - *prev(removed));
			setValidIndexTile.erase(removed);
			indexTile++;
		}
		bootCanReach[indexBoot] = mostStepBoot >= stepNeeded;
	}
	for (const bool &canReach : bootCanReach) {
		std::cout << canReach << '\n';
	}
	return 0;
}