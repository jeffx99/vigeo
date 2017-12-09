#include "point.hpp"

// RADIUS of point is 2 pixels and resolution is 8
void Point::draw(sf::RenderTarget* target, float k) {
	float radius = 3 * SCREEN_TO_PLANE, res = 8;
	
	sf::VertexArray v_array(sf::TriangleFan);
	v_array.append(sf::Vertex(plane_to_screen(pos), sf::Color::White));

	for (int i = 0; i <= res; ++i) {
		Coord n_point(radius * cosf((2. * i * M_PI) / res), radius * sinf((2. * i * M_PI) / res));
		v_array.append(sf::Vertex(plane_to_screen(n_point + pos), sf::Color::White));
	}

	target->draw(v_array);
}