#include "coord.hpp"

sf::Vector2f plane_to_screen(Coord plane_coord, float screen_height) {
	sf::Vector2f screen_coord(plane_coord.x, screen_height - plane_coord.y);
	return screen_coord;
}

Coord screen_to_plane(sf::Vector2f screen_coord, float screen_height) {
	Coord plane_coord(screen_coord.x, screen_height - screen_coord.y);
	return plane_coord;
}

float dist(Coord A, Coord B) {
	return sqrtf((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}
