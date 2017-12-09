#include "coord.hpp"

sf::Vector2f plane_to_screen(Coord plane_coord) {
	sf::Vector2f screen_coord(plane_coord.x * PLANE_TO_SCREEN, SCREEN_H - plane_coord.y * PLANE_TO_SCREEN);
	return screen_coord;
}

Coord screen_to_plane(sf::Vector2f screen_coord) {
	Coord plane_coord(screen_coord.x * SCREEN_TO_PLANE, (SCREEN_H - screen_coord.y) * SCREEN_TO_PLANE);
	return plane_coord;
}

