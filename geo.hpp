#pragma once
#include <utility>
#include "coord.hpp"
#include "circle.hpp"
#include "segment.hpp"

// Geo Functions
Coord circumcenter(Coord A, Coord B, Coord C);
Coord orthocenter(Coord A, Coord B, Coord C);
Coord centroid(Coord A, Coord B, Coord C);
Coord incenter(Coord A, Coord B, Coord C);

Coord project(Coord A, Coord B, Coord C); // Project A onto line BC
Coord reflect(Coord A, Coord B, Coord C); // Reflect A over line BC

Coord perp(Coord A, Coord B); // Provides vector perpendicular to line AB

std::pair<Coord, Coord> tangents(Coord P, Circle C);
Coord tangents(Coord P, Circle C, Coord except); // undefined if except is not one of the intersection points

// Intersect Functions
std::pair<Coord, Coord> circle_intersect(Circle A, Circle B);
Coord circle_intersect(Circle A, Circle B, Coord except); // undefined if except is not one of the intersection points
/*std::pair<Coord, Coord> circle_line_intersect(Circle A, Circle B);
Coord line_intersect(Segment l, Segment m);*/
Coord line_intersect(Coord p1, Coord p2, Coord p3, Coord p4);
