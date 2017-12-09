#include "triangle.hpp"

Coord circumcenter(Coord A, Coord B, Coord C) {
	Vector a = B - C, b = C - A, c = A - B;
	float aa = dot(A, A), bb = dot(B, B), cc = dot(C, C);
	float d = 2.0f * (A.x*a.y + B.x*b.y + C.x*c.y);

	Coord U;
	U.x = (aa*a.y + bb*b.y + cc*c.y) / d;
	U.y = -(aa*a.x + bb*b.x + cc*c.x) / d;

	return U;
}

Coord orthocenter(Coord A, Coord B, Coord C) {
	Coord O = circumcenter(A, B, C);
	return A + B + C - 2 * O;
}

Coord centroid(Coord A, Coord B, Coord C) {
	return (A + B + C) / 3;
}

Coord incenter(Coord A, Coord B, Coord C) {
	float a = length(B, C), b = length(C, A), c = length(A, B);

	return (a*A + b*B + c*C) / (a + b + c);
}
