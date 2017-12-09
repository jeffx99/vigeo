#pragma once
#include <utility>
#include "coord.hpp"
#include "general.hpp"
#include "segment.hpp"
#include "circle.hpp"
#include "triangle.hpp"

/*std::pair<Coord, Coord> tangents(Coord P, Circle C);
Coord tangents(Coord P, Circle C, Coord except); // undefined if except is not one of the intersection points

// Intersect Functions
std::pair<Coord, Coord> circle_intersect(Circle A, Circle B);
Coord circle_intersect(Circle A, Circle B, Coord except); // undefined if except is not one of the intersection points*/
/*std::pair<Coord, Coord> circle_line_intersect(Circle A, Circle B);
Coord line_intersect(Segment l, Segment m);*/
Coord line_intersect(Coord p1, Coord p2, Coord p3, Coord p4);
