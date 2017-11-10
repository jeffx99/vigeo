#pragma once
#include "primitive.hpp"
#include "coord.hpp"

class Point : public Primitive {
public:
	Coord pos;

	Point(Coord pos) : pos(pos) {}
	void draw(sf::RenderTarget* target, float t);
};