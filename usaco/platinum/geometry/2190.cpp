#include <bits/stdc++.h>

struct Point {
	int x, y;

	Point(int inputX = 0, int inputY = 0) : x(inputX), y(inputY) {}

	friend std::istream &operator>>(std::istream &input, Point &point) {
		input >> point.x >> point.y;
		return input;
	}
};

long long compress(long long num) {
	if (num > 0) {
		return 1;
	} else if (num < 0) {
		return -1;
	} else {
		return 0;
	}
}

long long collinear(Point point1, Point point2, Point point3) {
	return compress(1ll * (point1.y - point2.y) * (point3.x - point2.x) - 1ll * (point1.x - point2.x) * (point3.y - point2.y));
}

bool isOverlappingRectangle(Point point1, Point point2, Point point3, Point point4) {
	// Rectangle 1
	int x1 = std::min(point1.x, point2.x);
	int y1 = std::min(point1.y, point2.y);
	int x2 = std::max(point1.x, point2.x);
	int y2 = std::max(point1.y, point2.y);
	// Retangle 2
	int x3 = std::min(point3.x, point4.x);
	int y3 = std::min(point3.y, point4.y);
	int x4 = std::max(point3.x, point4.x);
	int y4 = std::max(point3.y, point4.y);
	return x2 < x3 || x4 < x1 || y2 < y3 || y4 < y1;
}

bool isDifferentSide(Point point1, Point point2, Point point3, Point point4) {
	if (collinear(point1, point2, point3) * collinear(point1, point2, point4) > 0) {
		return false;
	}
	if (collinear(point3, point4, point1) * collinear(point3, point4, point2) > 0) {
		return false;
	}
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		Point point1, point2, point3, point4;
		std::cin >> point1 >> point2 >> point3 >> point4;
		if (isOverlappingRectangle(point1, point2, point3, point4)) {
			std::cout << "NO" << '\n';
		} else if (isDifferentSide(point1, point2, point3, point4)) {
			std::cout << "YES" << '\n';
		} else {
			std::cout << "NO" << '\n';
		}
	}
	return 0;
}