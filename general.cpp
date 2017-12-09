#include "general.hpp"

Vector perp(Vector v) {
	return Vector(-v.y, v.x);
}

float length(Coord A, Coord B) {
	return sqrtf(dot(A - B, A - B));
}

float dot(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}

float cross(Vector a, Vector b) {
	return dot(perp(a), b);
}
