#pragma once
#include "geo.hpp"

struct Segment {
	Coord P1, P2;

	Segment(Coord P1, Coord P2) : P1(P1), P2(P2) {}
};

struct Line {
	Coord P1, P2;

	Line(Coord P1, Coord P2) : P1(P1), P2(P2) {}
};

Vector perp(Segment s);
Vector perp(Line l);
Coord project(Coord P, Segment s); // Project P onto segment s
Coord project(Coord P, Line l); // Project P onto segment s
Coord reflect(Coord P, Segment s); // Reflect P over line l
Coord reflect(Coord P, Line l); // Reflect P over line l
Coord line_intersect(Line l1, Line l2);
