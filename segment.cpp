#include "segment.hpp"

Vector perp(Segment s) {
	return perp(s.P1 - s.P2);
}

Vector perp(Line l) {
	return perp(l.P1 - l.P2);
}

Coord project(Coord P, Segment s) {
	Vector u = s.P2 - s.P1;
	Vector v = P - s.P1;
	return s.P1 + (dot(u,v) / dot(u, u)) * u;
}

Coord project(Coord P, Line l) {
	Vector u = l.P2 - l.P1;
	Vector v = P - l.P1;
	return l.P1 + (dot(u, v) / dot(u, u)) * u;
}

Coord reflect(Coord P, Segment s) {
	return 2 * project(P, s) - P;
}

Coord reflect(Coord P, Line l) {
	return 2 * project(P, l) - P;
}

Coord line_intersect(Line l1, Line l2) {
	float c1 = cross(l1.P1, l1.P2), c2 = cross(l2.P1, l2.P2), c3 = cross(l1.P1 - l1.P2, l2.P1 - l2.P2);

	float Px = (c1 * (l2.P1.x - l2.P2.x) - c2 * (l1.P1.x - l1.P2.x)) / c3;
	float Py = (c1 * (l2.P1.y - l2.P2.y) - c2 * (l1.P1.y - l1.P2.y)) / c3;

	return Coord(Px, Py);
}
