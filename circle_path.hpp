#pragma once
#include "path.hpp"
#include "geo.hpp"

class CirclePath : public Path {
public:
	CirclePath(Coord center, Coord other) {
		float radius = length(other, center);
		float res = 50; // 50 equally spaced points
		construct_path(center, radius, res);
	}

	CirclePath(Coord center, float radius) {
		float res = 50; // 50 equally spaced points
		construct_path(center, radius, res);
	}

private:
	// create path with set resolution
	void construct_path(Coord center, float radius, int res);
};