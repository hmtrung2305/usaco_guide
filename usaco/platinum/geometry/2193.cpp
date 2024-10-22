#include <bits/stdc++.h>

struct Point {
	int x, y;

	Point(int inputX = 0, int inputY = 0) : x(inputX), y(inputY) {}

	Point operator-(const Point &other) {
		return {x - other.x, y - other.y};
	}

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
	std::vector<Point> verticesPolygon(numVertex);
	for (Point &vertex : verticesPolygon) {
		std::cin >> vertex;
	}
	verticesPolygon.emplace_back(verticesPolygon[0]);
	long long doubleArea = 0;
	for (int vertex = 0; vertex < numVertex; vertex++) {
		doubleArea += 1ll * verticesPolygon[vertex].x * verticesPolygon[vertex + 1].y - 1ll * verticesPolygon[vertex].y * verticesPolygon[vertex + 1].x;
	}
	if (doubleArea < 0) {
		doubleArea = -doubleArea;
	}
	long long totalPointOnBoundary = 0;
	for (int vertex = 0; vertex < numVertex; vertex++) {
		Point distance = verticesPolygon[vertex + 1] - verticesPolygon[vertex];
		int countPointOnBoundary = std::__gcd(abs(distance.x), abs(distance.y));
		totalPointOnBoundary += countPointOnBoundary;
	}
	long long countPointInside = (doubleArea - totalPointOnBoundary) / 2 + 1;
	std::cout << countPointInside << ' ' << totalPointOnBoundary;
	return 0;

}