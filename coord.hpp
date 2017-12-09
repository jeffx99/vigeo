#pragma once
#define _USE_MATH_DEFINES
#include <SFML/System/Vector2.hpp>
#include <math.h>

#define COORD_EPSILON 0.00001f
#define PLANE_TO_SCREEN 30.0f
#define SCREEN_TO_PLANE 0.0333333333f
#define SCREEN_H 540

struct Coord;
using Vector = Coord;

struct Coord {
	float x, y;
	bool exists = true;

	Coord() {};
	Coord(float x, float y) : x(x), y(y) {};

	Coord& operator +=(const Coord& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	Coord& operator -=(const Coord& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}
	Coord& operator *=(const float rhs) {
		x *= rhs;
		y *= rhs;
		return *this;
	}
	Coord& operator /=(const float rhs) {
		x /= rhs;
		y /= rhs;
		return *this;
	}
	
	bool operator ==(const Coord rhs) {
		return(fabsf(x - rhs.x) + fabsf(y - rhs.y) <= COORD_EPSILON);
	}

};

sf::Vector2f plane_to_screen(Coord plane_coord);
Coord screen_to_plane(sf::Vector2f screen_coord);

inline Coord operator +(Coord lhs, const Coord& rhs) {
	lhs += rhs;
	return lhs;
}

inline Coord operator -(Coord lhs, const Coord& rhs) {
	lhs -= rhs;
	return lhs;
}

inline Coord operator *(const float lhs, Coord rhs) {
	rhs *= lhs;
	return rhs;
}

inline Coord operator /(Coord lhs, const float rhs) {
	lhs /= rhs;
	return lhs;
}