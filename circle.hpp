#pragma once
#include "primitive.hpp"
#include "point.hpp"

class Circle : public Primitive {
public:
	Coord center;
	Coord other;
	float radius;

	Circle() {}
	Circle(Coord center, Coord other) : center(center) { 
		radius = dist(other, center);
	};

	Circle(Coord center, float radius) : center(center), radius(radius) {};
	void draw(sf::RenderTarget* target, float t);
};