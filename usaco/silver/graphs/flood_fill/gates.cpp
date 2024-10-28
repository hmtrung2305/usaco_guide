#include <bits/stdc++.h>

int main() {
	freopen("gates.in", "r", stdin);
	freopen("gates.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthPath;
	std::cin >> lengthPath;
	std::string path;
	std::cin >> path;
	std::set<std::pair<int, int>> visitedNode;
	std::set<std::pair<std::pair<int, int>, std::pair<int, int>>> visitedEdge;
	int result = 0; 
	std::pair<int, int> previousPosition{0, 0};
	visitedNode.insert(previousPosition);
	int currentX = 0, currentY = 0;
	for (const char &step : path) {
		if (step == 'N') {
			currentY++;
		} else if (step == 'S') {
			currentY--;
		} else if (step == 'E') {
			currentX++;
		} else {
			currentX--;
		}
		if (visitedEdge.find(std::make_pair(std::make_pair(currentX, currentY), previousPosition)) == visitedEdge.end() &&
			visitedNode.find(std::make_pair(currentX, currentY)) != visitedNode.end()) {
			result++;
		}
		visitedEdge.insert(std::make_pair(std::make_pair(currentX, currentY), previousPosition));
		visitedEdge.insert(std::make_pair(previousPosition, std::make_pair(currentX, currentY)));
		visitedNode.insert(std::make_pair(currentX, currentY));
		previousPosition = std::make_pair(currentX, currentY);
	}
	std::cout << result;
	return 0;
}