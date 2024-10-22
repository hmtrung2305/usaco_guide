#include <bits/stdc++.h>
 
struct Point {
	int x, y;
 
	Point(int inputX = 0, int inputY = 0) : x(inputX), y(inputY) {}
 
	friend std::istream &operator>>(std::istream &input, Point &point) {
		input >> point.x >> point.y;
		return input;
	}
};
 
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numVertex;
	std::cin >> numVertex;
	std::vector<Point> vertices(numVertex);
	for (auto &vertex : vertices) {
		std::cin >> vertex;
	}
	vertices.emplace_back(vertices[0]);
	long long area = 0;
	for (int index = 0; index < (int)vertices.size() - 1; index++) {
		area += 1ll * vertices[index].x * vertices[index + 1].y - 1ll * vertices[index].y * vertices[index + 1].x;
	}
	std::cout << (area < 0 ? -area : area);
	return 0;
}