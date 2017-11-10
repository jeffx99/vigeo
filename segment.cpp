#include "segment.hpp"
#include <iostream>

// Thickness is 1 pixel(s)
void Segment::draw(sf::RenderTarget * target, float k) {
	float weight = 0.5f;
	sf::Vector2f end1_pos = plane_to_screen(end1, target->getSize().y);
	sf::Vector2f end2_pos = plane_to_screen(end2, target->getSize().y);

	float angle = atan2f(end2_pos.y - end1_pos.y, end2_pos.x - end1_pos.x);
	sf::Vector2f offset(cosf(angle + 0.5f * M_PI), sinf(angle + 0.5f * M_PI));
	offset *= weight;

	sf::VertexArray v_array(sf::TriangleStrip);
	v_array.append(sf::Vertex(end1_pos + offset, sf::Color::Cyan));
	v_array.append(sf::Vertex(end1_pos - offset, sf::Color::Cyan));
	v_array.append(sf::Vertex(end1_pos + k*(end2_pos - end1_pos) + offset, sf::Color::Cyan));
	v_array.append(sf::Vertex(end1_pos + k*(end2_pos - end1_pos) - offset, sf::Color::Cyan));

	target->draw(v_array);
}

void Tick::draw(sf::RenderTarget * target, float k) {
	float length = 20.f;
	sf::Vector2f end1_pos = plane_to_screen(end1, target->getSize().y);
	sf::Vector2f end2_pos = plane_to_screen(end2, target->getSize().y);
	sf::Vector2f mid_pos = (end1_pos + end2_pos) * 0.5f;

	float angle = atan2f(end2_pos.y - end1_pos.y, end2_pos.x - end1_pos.x);
	sf::Vector2f perp_offset(cosf(angle + 0.5f * M_PI), sinf(angle + 0.5f * M_PI));
	perp_offset *= (length * 0.5f);

	sf::Vector2f para_offset(-sinf(angle + 0.5f * M_PI), cosf(angle + 0.5f * M_PI));
	para_offset *= length;

	sf::Vector2f step_offset = para_offset / float(count + 1);

	sf::VertexArray v_array(sf::Lines);
	for (int i = 1; i <= count; ++i) {
		v_array.append(sf::Vertex(mid_pos - perp_offset - para_offset + float(i) * step_offset, sf::Color::White));
		v_array.append(sf::Vertex(mid_pos + (2 * k - 1)*perp_offset - para_offset + float(i) * step_offset, sf::Color::White));
		//v_array.append(sf::Vertex(end1_pos + k*(end2_pos - end1_pos) + offset, sf::Color::Cyan));
		//v_array.append(sf::Vertex(end1_pos + k*(end2_pos - end1_pos) - offset, sf::Color::Cyan));
	}
	target->draw(v_array);
}

void Line::draw(sf::RenderTarget * target, float k) {
	float length = 600.f; // how far are we going in either direction
	float weight = 0.5f;
	sf::Vector2f p1_pos = plane_to_screen(p1, target->getSize().y);
	sf::Vector2f p2_pos = plane_to_screen(p2, target->getSize().y);
	sf::Vector2f start = 0.5f * (p1_pos + p2_pos);

	float angle = atan2f(p2_pos.y - p1_pos.y, p2_pos.x - p1_pos.x);
	sf::Vector2f dir(cosf(angle), sinf(angle));
	sf::Vector2f offset(cosf(angle + 0.5f * M_PI), sinf(angle + 0.5f * M_PI));
	offset *= weight;

	sf::VertexArray v_array(sf::TriangleStrip);
	v_array.append(sf::Vertex(start - k*length*dir + offset, sf::Color(0, 128, 255)));
	v_array.append(sf::Vertex(start - k*length*dir - offset, sf::Color(0, 128, 255)));
	v_array.append(sf::Vertex(start + k*length*dir + offset, sf::Color(0, 128, 255)));
	v_array.append(sf::Vertex(start + k*length*dir - offset, sf::Color(0, 128, 255)));

	target->draw(v_array);
}
