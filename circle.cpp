#include "circle.hpp"

void Circle::draw(sf::RenderTarget * target, float k) {
	float width = 0.5;
	int res = 100;
	sf::Vector2f s_center = plane_to_screen(center, target->getSize().y);

	sf::VertexArray v_array(sf::TriangleStrip);

	for (int i = 0; i <= res; ++i) {
		sf::Vector2f n_point(radius * cosf((2. * k * i * M_PI) / res), radius * sinf((2. * k * i * M_PI) / res));
		sf::Vector2f offset = n_point / radius * width;

		v_array.append(sf::Vertex(s_center + n_point + offset, sf::Color::Yellow));
		v_array.append(sf::Vertex(s_center + n_point - offset, sf::Color::Yellow));
	}

	target->draw(v_array);
}
