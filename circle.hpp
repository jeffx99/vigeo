#pragma once
#include "coord.hpp"

struct Circle {
	Coord center;
	float r;

	Circle(Coord center, float radius) : center(center), r(radius) {}
	Circle(Coord center, Coord other) : center(center), r(length(center, other)) {}
};