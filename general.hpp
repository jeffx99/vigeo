#pragma once
#include "coord.hpp"

/* General Geometry Techniques
	- finding the vector perpendicular to another
*/

float length(Coord A, Coord B = Coord(0, 0));
float dot(Vector a, Vector b);
float cross(Vector a, Vector b);
Vector perp(Vector v); // Provides vector perpendicular to another
