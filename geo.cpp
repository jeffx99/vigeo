#include "geo.hpp"

/*
std::pair<Coord, Coord> tangents(Coord P, Circle C) {
	Coord O = 0.5f * (P + C.center);
	Circle OP(O, P);
	OP.auxiliary = true;


	return circle_intersect(OP, C);
}

Coord tangents(Coord P, Circle C, Coord except) {
	std::pair<Coord, Coord> points = tangents(P, C);
	if (points.first == except)
		return points.second;
	else if (points.second == except)
		return points.first;
	return Coord();
}

std::pair<Coord, Coord> circle_intersect(Circle A, Circle B) {
	Coord C1, C2;
	Coord P0 = A.center, P1 = B.center;
	float d = dist(P0, P1);
	float rs = A.radius + B.radius;
	float rd = A.radius - B.radius;
	if (d > rs) {
		C1.exists = false;
		C2.exists = false;
		return std::pair<Coord, Coord>(C1, C2);
	}
	if (d < fabsf(rd)) {
		C1.exists = false;
		C2.exists = false;
		return std::pair<Coord, Coord>(C1, C2);
	}

	float a = (rs * rd + d * d) / (2 * d);
	float h = sqrtf(A.radius * A.radius - a * a);

	Coord P = P0 + a*(P1 - P0) / d;
	
	C1.x = P.x + h*(P1.y - P0.y) / d;
	C1.y = P.y - h*(P1.x - P0.x) / d;
	C2.x = P.x - h*(P1.y - P0.y) / d;
	C2.y = P.y + h*(P1.x - P0.x) / d;

	return std::pair<Coord, Coord>(C1, C2);
}

Coord circle_intersect(Circle A, Circle B, Coord except) {
	std::pair<Coord, Coord> points = circle_intersect(A, B);
	if (points.first == except)
		return points.second;
	else if (points.second == except)
		return points.first;
	return Coord();
}
*/
Coord line_intersect(Coord p1, Coord p2, Coord p3, Coord p4) {
	float Px = ((p1.x*p2.y - p1.y*p2.x)*(p3.x - p4.x) - (p1.x - p2.x)*(p3.x*p4.y - p3.y*p4.x)) / ((p1.x - p2.x)*(p3.y - p4.y) - (p1.y - p2.y)*(p3.x - p4.x));
	float Py = ((p1.x*p2.y - p1.y*p2.x)*(p3.y - p4.y) - (p1.y - p2.y)*(p3.x*p4.y - p3.y*p4.x)) / ((p1.x - p2.x)*(p3.y - p4.y) - (p1.y - p2.y)*(p3.x - p4.x));
	return Coord(Px, Py);
}
