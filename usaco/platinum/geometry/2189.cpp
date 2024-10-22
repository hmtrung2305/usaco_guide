#include <bits/stdc++.h>

struct Point {
	int x, y;

	Point(int inputX = 0, int inputY = 0) : x(inputX), y(inputY) {}

	friend std::istream &operator>>(std::istream &input, Point &point) {
		input >> point.x >> point.y;
		return input;
	}
};

long long collinear(Point point1, Point point2, Point point3) {
	return 1ll * (point1.y - point2.y) * (point3.x - point2.x) - 1ll * (point1.x - point2.x) * (point3.y - point2.y);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		Point point1, point2, point3;
		std::cin >> point1 >> point2 >> point3;
		if (collinear(point1, point2, point3) == 0) {
			std::cout << "TOUCH" << '\n';
		} else if (collinear(point1, point2, point3) < 0) {
			std::cout << "RIGHT" << '\n';
		} else {
			std::cout << "LEFT" << '\n';
		}
	}
	return 0;
}