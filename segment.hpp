#pragma once
#include "primitive.hpp"
#include "point.hpp"

class Segment : public Primitive {
public:
	Coord end1, end2; //endpoints

	Segment() {}
	Segment(Coord p1, Coord p2) : end1(p1), end2(p2) {};
 	void draw(sf::RenderTarget* target, float t);
};

class Tick : public Primitive {
public:
	Coord end1, end2;
	int count = 2;
	
	Tick() {}
	Tick(Segment seg, unsigned int count = 1) : end1(seg.end1), end2(seg.end2), count(count) {};
	Tick(Coord p1, Coord p2, unsigned int count = 1) : end1(p1), end2(p2), count(count) {};
	void draw(sf::RenderTarget* target, float t);
};

class Line : public Primitive {
public:
	Coord p1, p2; //points on the line

	Line() {}
	Line(Coord p1, Coord p2) : p1(p1), p2(p2) {};
	void draw(sf::RenderTarget* target, float t);
};