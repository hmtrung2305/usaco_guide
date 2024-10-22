#include <bits/stdc++.h>

template<class TypeData> struct Point { /// 2D-Point Structure
	TypeData x, y; // should use double

	Point(const TypeData &inputX = 0, const TypeData &inputY = 0) : x(inputX), y(inputY) {}

	void swap(Point &other) {
		std::swap(x, other.x);
		std::swap(y, other.y);
	}
	template<class TypeDataObject> explicit operator Point<TypeDataObject> () const {
		return Point<TypeDataObject>(static_cast<TypeDataObject>(x), static_cast<TypeDataObject>(y));
	}
	template<class TypeDataObject> Point operator=(const Point<TypeDataObject> &other) {
		x = other.x;
		y = other.y;
		return *this;
	}
	template<class TypeDataObject> Point& operator+=(const Point<TypeDataObject> &other) {
		x = x + other.x;
		y = y + other.y;
		return *this;
	}
	template<class TypeDataObject> Point& operator-=(const Point<TypeDataObject> &other) {
		x = x - other.x;
		y = y - other.y;
		return *this;
	}
	template<class TypeDataObject> Point& operator*=(const TypeDataObject &other) {
		x = x * other;
		y = y * other;
		return *this;
	}
	template<class TypeDataObject> Point& operator/=(const TypeDataObject &other) {
		x = x / other;
		y = y / other;
		return *this;
	}

	friend std::istream &operator>>(std::istream &input, Point &point) {
		input >> point.x >> point.y;
		return input;
	}
	friend std::ostream &operator<<(std::ostream &output, const Point &point) {
		output << point.x << ' ' << point.y;
		return output;
	}
};

/// Common Function
template<class TypeDataObject> 
inline Point<TypeDataObject> makePoint(const TypeDataObject &x, const TypeDataObject &y) {
	return Point<TypeDataObject>(x, y);
}
template<class TypeDataObject> 
void swap(Point<TypeDataObject> &point1, Point<TypeDataObject> &point2) {
	return point1.swap(point2);
}

/// Operator
template<class TypeDataObject1, class TypeDataObject2>
inline Point<TypeDataObject1> operator+(const Point<TypeDataObject1> &point1, const Point<TypeDataObject2> &point2) {
	return makePoint(point1.x + point2.x, point1.y + point2.y);
}
template<class TypeDataObject>
inline Point<TypeDataObject> operator-(const Point<TypeDataObject> &point) {
	return makePoint(-point.x, -point.y);
}
template<class TypeDataObject1, class TypeDataObject2>
inline Point<TypeDataObject1> operator-(const Point<TypeDataObject1> &point1, const Point<TypeDataObject2> &point2) {
	return makePoint(point1.x - point2.x, point1.y - point2.y);
}
template<class TypeDataObject1, class TypeDataObject2>
inline Point<TypeDataObject2> operator*(const TypeDataObject1 &factor, const Point<TypeDataObject2> &point) {
	return makePoint(factor * point.x, factor * point.y);
}
template<class TypeDataObject1, class TypeDataObject2>
inline Point<TypeDataObject1> operator*(const Point<TypeDataObject1> &point, const TypeDataObject2 &factor) {
	return makePoint(point.x * factor, point.y * factor);
}
template<class TypeDataObject1, class TypeDataObject2>
inline TypeDataObject1 operator*(const Point<TypeDataObject1> &point1, const Point<TypeDataObject2> &point2) {
	return point1.x * point2.x + point1.y * point2.y;
}
template<class TypeDataObject1, class TypeDataObject2>
inline Point<TypeDataObject1> operator/(const Point<TypeDataObject1> &point, const TypeDataObject2 &factor) {
	return makePoint(point.x / factor, point.y / factor);
}
template<class TypeDataObject1, class TypeDataObject2>
inline bool operator==(const Point<TypeDataObject1> &point1, const Point<TypeDataObject2> &point2) {
	return point1.x == point2.x && point1.y == point2.y;
}
template<class TypeDataObject1, class TypeDataObject2>
inline bool operator!=(const Point<TypeDataObject1> &point1, const Point<TypeDataObject2> &point2) {
	return !(point1 == point2);
}
// point1 < point2 if (point1->point2) is counter-clockwise
template<class TypeDataObject1, class TypeDataObject2>
inline bool operator<(const Point<TypeDataObject1> &point1, const Point<TypeDataObject2> &point2) {
	return point1.y < point2.y || (point1.y == point2.y && point1.x < point2.x);
}
template<class TypeDataObject1, class TypeDataObject2>
inline bool operator>(const Point<TypeDataObject1> &point1, const Point<TypeDataObject2> &point2) {
	return point2 < point1;
}
template<class TypeDataObject1, class TypeDataObject2>
inline bool operator<=(const Point<TypeDataObject1> &point1, const Point<TypeDataObject2> &point2) {
	return !(point1 > point2);
}
template<class TypeDataObject1, class TypeDataObject2>
inline bool operator>=(const Point<TypeDataObject1> &point1, const Point<TypeDataObject2> &point2) {
	return !(point1 < point2);
}

/// Type Counter-clockwise
template<class TypeDataObject1, class TypeDataObject2> 
inline TypeDataObject1 trigonometricSense(const Point<TypeDataObject1> &point1, const Point<TypeDataObject2> &point2) {
	return point1.x * point2.y - point1.y * point2.x;
}
// = 0 - collinear
// > 0 - clockwise
// < 0 - counter-clockwise
template<class TypeDataObject1, class TypeDataObject2> 
inline TypeDataObject1 typeCounterClockwise(const Point<TypeDataObject1> &point1, const Point<TypeDataObject2> &point2) {
	return trigonometricSense(point1, point2);
}
template<class TypeDataObject1, class TypeDataObject2, class TypeDataObject3> 
inline TypeDataObject1 typeCounterClockwise(const Point<TypeDataObject1> &point1, const Point<TypeDataObject2> &point2, const Point<TypeDataObject3> &origin) {
	return trigonometricSense(point1 - origin, point2 - origin);
}

/// Angles and rotations (counter-clockwise)
// Angles
template<class TypeDataObject> 
inline long double angle(const Point<TypeDataObject> &point) {
	return atan2l(point.y, point.x);
}
template<class TypeDataObject1, class TypeDataObject2> 
inline long double angle(const Point<TypeDataObject1> &point1, const Point<TypeDataObject2> &point2) {
	return atan2l(trigonometricSense(point1, point2), point1 * point2);
}
template<class TypeDataObject1, class TypeDataObject2, class TypeDataObject3> 
inline long double angle(const Point<TypeDataObject1> &point1, const Point<TypeDataObject2> &point2, const Point<TypeDataObject3> &origin) {
	return angle(point1 - origin, point2 - origin);
}
// Rotations
template<class TypeDataObject1, class TypeDataObject2, class TypeDataObject3> 
inline Point<TypeDataObject1> rotate(const Point<TypeDataObject1> &point, const TypeDataObject2 &angleSin, const TypeDataObject3 &angleCos) {
	return makePoint(angleCos * point.x - angleSin * point.y, angleSin * point.x - angleCos * point.y);
}
template<class TypeDataObject1, class TypeDataObject2> 
inline Point<TypeDataObject1> rotate(const Point<TypeDataObject1> &point, const TypeDataObject2 &angle) {
	return rotate(point, sin(angle), cos(angle));
}
template<class TypeDataObject1, class TypeDataObject2, class TypeDataObject3> 
inline Point<TypeDataObject1> rotate(const Point<TypeDataObject1> &point, const TypeDataObject2 &angle, const Point<TypeDataObject3> &origin) {
	return origin + rotate(point - origin, angle);
}
template<class TypeDataObject> 
inline Point<TypeDataObject> perpendicular(const Point<TypeDataObject> &point) {
	return makePoint(-point.y, point.x);
}

/// Distances
template<class TypeDataObject>
inline TypeDataObject square(const Point<TypeDataObject> &point) {
	return point * point;
}
template<class TypeDataObject>
inline TypeDataObject lengthVector(const Point<TypeDataObject> &point) {
	return sqrt(square(point));
}
template<class TypeDataObject1, class TypeDataObject2>
inline TypeDataObject1 lengthBisector(const Point<TypeDataObject1> &point1, const Point<TypeDataObject2> &point2) {
	return point1 * lengthVector(point2) + point2 * lengthVector(point1);
}
template<class TypeDataObject1, class TypeDataObject2>
inline TypeDataObject1 distanceEuclidean(const Point<TypeDataObject1> &point1, const Point<TypeDataObject2> &point2) {
	return lengthVector(point1 - point2);
}
template<class TypeDataObject1, class TypeDataObject2>
inline TypeDataObject1 distanceManhattan(const Point<TypeDataObject1> &point1, const Point<TypeDataObject2> &point2) {
	return abs(point1.x - point2.x) + abs(point1.y - point2.y);
}

/// Area
template<class TypeDataObject>
inline TypeDataObject areaPolygon(std::vector<Point<TypeDataObject>> &pointPolygon) {
	TypeDataObject area = trigonometricSense(pointPolygon.back(), pointPolygon[0]);
	for (int index = 0; index < (int)pointPolygon.size() - 1; index++) {
		area += trigonometricSense(pointPolygon[index], pointPolygon[index + 1]);
	}
	return area / 2;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numPointPolygon;
	while (std::cin >> numPointPolygon && numPointPolygon != 0) {
		std::vector<Point<long double>> pointPolygon(numPointPolygon);
		for (Point<long double> &point : pointPolygon) {
			std::cin >> point;
		}
		long double area = areaPolygon(pointPolygon);
		if (area > 0) {
			std::cout << std::fixed << std::setprecision(1) << "ccw " << area << '\n';
		} else {
			std::cout << std::fixed << std::setprecision(1) << "cw " << -area << '\n';
		}
	}
	return 0;
}