#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCube;
	std::cin >> numCube;
	std::vector<int> sizeCube(numCube);
	for (int &size : sizeCube) {
		std::cin >> size;
	}
	std::multiset<int> setCube;
	for (int index = 0; index < numCube; index++) {
		auto iteratorIndex = setCube.upper_bound(sizeCube[index]);
		if (iteratorIndex == setCube.end()) {
			setCube.insert(sizeCube[index]);
		} else {
			setCube.erase(iteratorIndex);
			setCube.insert(sizeCube[index]);
		}
	}
	std::cout << (int)setCube.size();
	return 0;
}