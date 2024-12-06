#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthStreet, numLight;
	std::cin >> lengthStreet >> numLight;
	std::set<int> setPosition{0, lengthStreet};
	std::multiset<int> segments{lengthStreet};
	for (int light = 0; light < numLight; light++) {
		int positionLight;
		std::cin >> positionLight;
		auto iteratorRight = setPosition.upper_bound(positionLight);
		auto iteratorLeft = iteratorRight;
		iteratorLeft--;
		auto iteratorSegment = segments.lower_bound(*iteratorRight - *iteratorLeft);
		int segmentLeft = positionLight - *iteratorLeft;
		int segmentRight = *iteratorRight - positionLight;
		segments.erase(iteratorSegment);
		segments.insert(segmentLeft);
		segments.insert(segmentRight);
		std::cout << *segments.rbegin() << ' ';
		setPosition.insert(positionLight);
	}
	return 0;
}