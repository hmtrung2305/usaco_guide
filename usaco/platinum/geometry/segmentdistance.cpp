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

template<class TypeData>
struct Line { /// Line [A, B]
	Point<TypeData> pointA, directionVector; // pointA + parameter * directionVector

	Line() : pointA(), directionVector() {}
	Line(const Point<TypeData> &point1, const Point<TypeData> &point2, bool twoPoint = true)
		: pointA(point1), directionVector(twoPoint ? point2 - point1 : point2) {} 
	Line(const TypeData &xPoint1, const TypeData &yPoint1, const TypeData &xPoint2, const TypeData &yPoint2)
		: pointA(xPoint1, yPoint1), directionVector(xPoint2 - xPoint1, yPoint2 - yPoint1) {}

	void swap(Line &other) {
		std::swap(pointA, other.pointA);
		std::swap(directionVector, other.directionVector);
	}
	template<class TypeDataObject> explicit operator Line<TypeDataObject> () const {
		return Line<TypeDataObject>(Point<TypeDataObject>(pointA), Point<TypeDataObject>(directionVector), false);
	}
	template<class TypeDataObject> Line& operator=(const Line<TypeDataObject> &other) {
		pointA = other.pointA;
		directionVector = other.directionVector;
		return *this;
	}

	Point<TypeData> pointB() const {
		return pointA + directionVector;
	}
	operator bool() const {
		return directionVector != Point<TypeData>();
	}

	friend std::istream &operator>>(std::istream &input, Line &line) {
		Point<TypeData> &inputPointA = line.pointA;
		input >> inputPointA.x >> inputPointA.y;
		Point<TypeData> &inputPointB = line.directionVector; // change input point B to direction vector
		input >> inputPointB.x >> inputPointB.y;
		inputPointB -= inputPointA;
		return input;
	}
	friend std::ostream &operator<<(std::ostream &output, const Line &line) {
		output << line.pointA.x << ' ' << line.pointA.y << ' ' << line.pointB().x << ' ' << line.pointB().y;
		return output;
	}
};

/// Common Function
template<class TypeDataObject>
inline Line<TypeDataObject> makeLine(const Point<TypeDataObject> &pointA, const Point<TypeDataObject> &pointB, bool twoPoint = true) {
	return Line<TypeDataObject>(pointA, pointB, twoPoint);
}
template<class TypeDataObject>
void swap(Line<TypeDataObject> &line1, Line<TypeDataObject> &line2) {
	line1.swap(line2);
}

/// Check on line or on segment
template<class TypeDataObject1, class TypeDataObject2>
bool onLine(const Point<TypeDataObject1> &point, const Line<TypeDataObject2> &line) {
	if (!line) {
		return point == line.pointA;
	}
	return trigonometricSense((point - line.pointA), line.directionVector) == 0;
}
template<class TypeDataObject1, class TypeDataObject2>
bool onSegment(const Point<TypeDataObject1> &point, const Line<TypeDataObject2> &segment) {
	if (!segment) {
		return point == segment.pointA;
	}
	Point<TypeDataObject1> vectorA = segment.pointA - point, vectorB = segment.pointB() - point;
	return trigonometricSense(vectorA, vectorB) == 0 && (vectorA * vectorB) <= 0;
}

/// Distances
template<class TypeDataObject1, class TypeDataObject2> using TypeDataDistance = decltype(sqrt(TypeDataObject1() + TypeDataObject2()));
template<class TypeDataObject1, class TypeDataObject2>
TypeDataDistance<TypeDataObject1, TypeDataObject2> distanceLine(const Point<TypeDataObject1> &point, const Line<TypeDataObject2> &line) {
	if (!line) {
		return distanceEuclidean(point, line.pointA);
	}
	return abs(trigonometricSense(point - line.pointA, line.directionVector)) / lengthVector(line.directionVector);
}
template<class TypeDataObject1, class TypeDataObject2>
TypeDataDistance<TypeDataObject1, TypeDataObject2> distanceSegment(const Point<TypeDataObject1> &point, const Line<TypeDataObject2> &segment) {
	if (((point - segment.pointA) * segment.directionVector) <= 0) {
		return distanceEuclidean(point, segment.pointA);
	}
	if (((point - segment.pointB()) * segment.directionVector) >= 0) {
		return distanceEuclidean(point, segment.pointB());
	}
	return distanceLine(point, segment);
}

/// Find Point
template<class TypeDataObject1, class TypeDataObject2>
Point<TypeDataObject1> projection(const Point<TypeDataObject1> &point, const Line<TypeDataObject2> &line) {
	Point<TypeDataObject1> result = line.pointA;
	if (line) {
		result += line.directionVector * static_cast<TypeDataObject1>((point - line.pointA) * line.directionVector) / square(line.directionVector);
	}
	return result;
}
template<class TypeDataObject1, class TypeDataObject2>
Point<TypeDataObject1> reflection(const Point<TypeDataObject1> &point, const Line<TypeDataObject2> &line) {
	Point<TypeDataObject1> result = projection(point, line);
	result = 2 * result - point;
	return result;
}
template<class TypeDataObject1, class TypeDataObject2>
Point<TypeDataObject1> pointClosest(const Point<TypeDataObject1> &point, const Line<TypeDataObject2> &segment) {
	if (((point - segment.pointA) * segment.directionVector) <= 0) {
		return segment.pointA;
	} else if (((point - segment.pointB()) * segment.directionVector) >= 0) {
		return segment.pointB();
	} else {
		return projection(point, segment);
	}
}

/// Line Intersection
template<int TypeData> struct EndPointChecker{};
template<> struct EndPointChecker<0> { // no endpoint (ray)
	template<class TypeDataObject> bool operator()(const TypeDataObject &point1, const TypeDataObject &point2) const {
		return true;
	}
};
template<> struct EndPointChecker<1> { // closed endpoint
	template<class TypeDataObject> bool operator()(const TypeDataObject &point1, const TypeDataObject &point2) const {
		return point1 <= point2;
	}
};
template<> struct EndPointChecker<2> { // open endpoint
	template<class TypeDataObject> bool operator()(const TypeDataObject &point1, const TypeDataObject &point2) const {
		return point1 < point2;
	}
};

template<int leftPointA, int leftPointB, int rightPointA, int rightPointB, class TypeDataObject1, class TypeDataObject2, class TypeDataObject3>
bool intersectLines(const Line<TypeDataObject1> &line1, const Line<TypeDataObject2> &line2, Point<TypeDataObject3> &result) {
	if (!line1 || !line2) {
		return false;
	}
	// assert(line1 && line2);
	auto s = trigonometricSense(line1.directionVector, line2.directionVector);
	if (s == 0) {
		return false;
	}
	auto a = trigonometricSense(line2.pointA - line1.pointA, line2.directionVector);
	auto b = trigonometricSense(line2.pointA - line1.pointA, line1.directionVector);
	if (s < 0) {
		s = -s;
		a = -a;
		b = -b;
	}
	bool intersect = 
		EndPointChecker<leftPointA>()(decltype(a)(0), a) && EndPointChecker<leftPointB>()(a, s) &&
		EndPointChecker<leftPointA>()(decltype(b)(0), b) && EndPointChecker<leftPointB>()(b, s);
	if (intersect) {
		result = line1.pointA + line1.directionVector * static_cast<TypeDataObject3>(a) / s;
	}
	return intersect;
}
template<class TypeDataObject1, class TypeDataObject2, class TypeDataObject3>
bool intersectClosedSegments(const Line<TypeDataObject1> &line1, const Line<TypeDataObject2> &line2, Point<TypeDataObject3> &result) {
	return intersectLines<1, 1, 1, 1>(line1, line2, result);
}
template<class TypeDataObject1, class TypeDataObject2, class TypeDataObject3>
bool intersectSegments(const Line<TypeDataObject1> &line1, const Line<TypeDataObject2> &line2, Line<TypeDataObject3> &result) {
	auto s = trigonometricSense(line1.directionVector, line2.directionVector);
	auto a = trigonometricSense(line2.pointA - line1.pointA, line2.directionVector);
	if (s == 0) {
		if (a != 0) {
			return false;
		}
		auto pointALine1 = line1.pointA, pointBLine1 = line1.pointB();
		auto pointALine2 = line2.pointA, pointBLine2 = line2.pointB();
		if (pointALine1 > pointBLine1) {
			swap(pointALine1, pointBLine1);
		}
		if (pointALine2 > pointBLine2) {
			swap(pointALine2, pointBLine2);
		}
		result = Line<TypeDataObject3>(std::max(pointALine1, pointALine2), std::min(pointBLine1, pointBLine2));
		return result.directionVector >= Point<TypeDataObject3>();
	}
	auto b = trigonometricSense(line2.pointA - line1.pointA, line1.directionVector);
	if (s < 0) {
		s = -s;
		a = -a;
		b = -b;
	}
	bool intersect = 0 <= a && a <= s && 0 <= b && b <= s;
	if (intersect) {
		result = Line<TypeDataObject3>(line1.pointA + line1.directionVector * static_cast<TypeDataObject3>(a) / s, Point<TypeDataObject3>());
	}
	return intersect;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		Line<double> line1, line2;
		std::cin >> line1 >> line2;
		Point<double> pointA = line1.pointA, pointB = line1.pointB();
		Point<double> pointC = line2.pointA, pointD = line2.pointB();
		Point<double> pointIntersect;
		if (intersectClosedSegments(line1, line2, pointIntersect)) {
			std::cout << std::fixed << std::setprecision(2) << 0.00 << '\n';
		} else {
			std::cout << std::fixed << std::setprecision(2) <<
				std::min({distanceSegment(pointA, line2), distanceSegment(pointB, line2), 
					distanceSegment(pointC, line1), distanceSegment(pointD, line1)}) << '\n';
		}
	}
	return 0;
}