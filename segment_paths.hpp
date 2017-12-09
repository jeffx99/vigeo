#pragma once
#include "geo.hpp"
#include "path.hpp"
#include "point.hpp"

class SegmentPath : public Path {
public:
	SegmentPath() {}
	SegmentPath(Coord p1, Coord p2) {
		thickness = 1.0f;
		subpaths.push_back(vector<Coord>());
		colors.push_back(sf::Color::Cyan);
		
		subpaths[0].push_back(p1);
		subpaths[0].push_back(p2);
	};
};

class Tick : public Path {
public:
	Coord end1, end2;
	int count = 2;
	
	Tick() {}
	Tick(Coord p1, Coord p2, unsigned int count = 5) {
		subpaths.resize(count);
		colors.push_back(sf::Color::White);

		float tick_length = 0.66f;
		Coord mid = 0.5f * (p1 + p2);
		Coord normal = perp(p1 - p2); // half length of tick perp to line
		normal *= 0.5f * tick_length / length(normal);

		Coord offset = 0.25f * tick_length * (p1 - p2) / length(p1 - p2); // for multiple ticks, will fit in a 2x1 box

		for (int i = 0; i < count; ++i) {
			float k;
			if (count != 1) k = (float(2 * i) / (count - 1)) - 1; // o = 2i/c -1
			else k = 0;

			subpaths[i].push_back(mid + normal + k * offset);
			subpaths[i].push_back(mid - normal + k * offset);
		}
	};
};

class LinePath : public Path {
public:
	LinePath() {}
	LinePath(Coord p1, Coord p2) {
		thickness = 1.0f;
		subpaths.push_back(vector<Coord>());
		colors.push_back(sf::Color::Blue);

		/* We want the line to never end inside the plane
			- max length = sqrt(18^2 + 32^2)
		*/
		Coord m = 0.5f * (p1 + p2);
		Coord r = sqrtf(18 * 18 + 32 * 32) * (p1 - p2) / length(p1 - p2);

		subpaths[0].push_back(m + r);
		subpaths[0].push_back(m - r);
	};
};