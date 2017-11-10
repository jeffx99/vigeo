#include "point.hpp"

// RADIUS of point is 2 pixels and resolution is 8
void Point::draw(sf::RenderTarget* target, float k) {
	int radius = 3, res = 8;
	sf::Vector2f s_pos = plane_to_screen(pos, target->getSize().y);
	
	sf::VertexArray v_array(sf::TriangleFan);
	v_array.append(sf::Vertex(s_pos, sf::Color::White));

	for (int i = 0; i <= res; ++i) {
		sf::Vector2f n_point(radius * cosf((2. * i * M_PI) / res), radius * sinf((2. * i * M_PI) / res));
		v_array.append(sf::Vertex(n_point + s_pos, sf::Color::White));
	}

	target->draw(v_array);
}