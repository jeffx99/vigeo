#include "geo.hpp"

Coord circumcenter(Coord A, Coord B, Coord C) {
	float bcy = B.y - C.y, cay = C.y - A.y, aby = A.y - B.y;
	float bcx = B.x - C.x, cax = C.x - A.x, abx = A.x - B.x;
	float aa = (A.x*A.x + A.y*A.y), bb = (B.x*B.x + B.y*B.y), cc = (C.x*C.x + C.y*C.y);
	float d = 2.0f * (A.x*bcy + B.x*cay + C.x*aby);

	Coord U;
	U.x = (aa*bcy + bb*cay + cc*aby) / d;
	U.y = -(aa*bcx + bb*cax + cc*abx) / d;

	return U;
}

Coord orthocenter(Coord A, Coord B, Coord C) {
	Coord O = circumcenter(A, B, C);
	return A + B + C - 2*O;
}

Coord centroid(Coord A, Coord B, Coord C) {
	return (A + B + C) / 3;
}

Coord incenter(Coord A, Coord B, Coord C) {
	float a = dist(B, C), b = dist(C, A), c = dist(A, B);

	return (a*A + b*B + c*C) / (a + b + c);
}

Coord project(Coord A, Coord B, Coord C) {
	Coord Cp = C - B;
	Coord Ap = A - B;
	return B + ((Ap.x * Cp.x + Ap.y * Cp.y) / (Cp.x * Cp.x + Cp.y * Cp.y)) * Cp;
}

Coord reflect(Coord A, Coord B, Coord C) {
	return 2 * project(A, B, C) - A;
}

Coord perp(Coord A, Coord B) {
	return Coord(B.y - A.y, A.x - B.x);
}

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

Coord line_intersect(Coord p1, Coord p2, Coord p3, Coord p4) {
	float Px = ((p1.x*p2.y - p1.y*p2.x)*(p3.x - p4.x) - (p1.x - p2.x)*(p3.x*p4.y - p3.y*p4.x)) / ((p1.x - p2.x)*(p3.y - p4.y) - (p1.y - p2.y)*(p3.x - p4.x));
	float Py = ((p1.x*p2.y - p1.y*p2.x)*(p3.y - p4.y) - (p1.y - p2.y)*(p3.x*p4.y - p3.y*p4.x)) / ((p1.x - p2.x)*(p3.y - p4.y) - (p1.y - p2.y)*(p3.x - p4.x));
	return Coord(Px, Py);
}
