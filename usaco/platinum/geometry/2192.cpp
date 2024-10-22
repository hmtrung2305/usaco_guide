#include <bits/stdc++.h>

struct Point {
	int x, y;

	Point(int inputX = 0, int inputY = 0) : x(inputX), y(inputY) {}

	friend std::istream &operator>>(std::istream &input, Point &point) {
		input >> point.x >> point.y;
		return input;
	}
};

bool onSegment(const Point &pointTarget, const Point &point1, const Point &point2) {
	int minX = std::min(point1.x, point2.x);
	int maxX = std::max(point1.x, point2.x);
	int minY = std::min(point1.y, point2.y);
	int maxY = std::max(point1.y, point2.y);
	return 1ll * (pointTarget.y - point1.y) * (point2.x - point1.x) == 1ll * (pointTarget.x - point1.x) * (point2.y - point1.y) &&
		minX <= pointTarget.x && pointTarget.x <= maxX && minY <= pointTarget.y && pointTarget.y <= maxY;
}

long long collinear(const Point &point1, const Point &point2, const Point &point3) {
	return 1ll * (point1.y - point2.y) * (point3.x - point2.x) - 1ll * (point1.x - point2.x) * (point3.y - point2.y);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numVertex, numPoint;
	std::cin >> numVertex >> numPoint;
	std::vector<Point> verticesPolygon(numVertex);
	for (Point &vertex : verticesPolygon) {
		std::cin >> vertex;
	}
	for (int query = 0; query < numPoint; query++) {
		Point point;
		std::cin >> point;
		int countOneSide = 0;
		bool isOnSegment = false;
		for (int vertex = 0; vertex < numVertex; vertex++) {
			int nextVertex = (vertex + 1) % numVertex;
			if (onSegment(point, verticesPolygon[vertex], verticesPolygon[nextVertex])) {
				isOnSegment = true;
				break;
			}
			if (verticesPolygon[vertex].y <= point.y && point.y < verticesPolygon[nextVertex].y &&
				collinear(point, verticesPolygon[vertex], verticesPolygon[nextVertex]) > 0) {
				countOneSide++;
			} else if (verticesPolygon[nextVertex].y <= point.y && point.y < verticesPolygon[vertex].y &&
				collinear(point, verticesPolygon[nextVertex], verticesPolygon[vertex]) > 0) {
				countOneSide++;
			}
		}
		if (isOnSegment) {
			std::cout << "BOUNDARY" << '\n';
		} else {
			std::cout << (countOneSide % 2 == 1 ? "INSIDE" : "OUTSIDE") << '\n';
		}
	}
	return 0;

}