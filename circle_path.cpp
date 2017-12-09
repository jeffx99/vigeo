#include "circle_path.hpp"

void CirclePath::construct_path(Coord center, float radius, int res) {
	subpaths.push_back(vector<Coord>());
	colors.push_back(sf::Color::Yellow);
	for (int i = 0; i <= res; ++i) {
		subpaths[0].push_back(center + Coord(radius * cosf((2.0f * i * M_PI) / res), radius * sinf((2.0f * i * M_PI) / res)));
	}
}