#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "primitive.hpp"
#include <vector>
#include <map>

class Timeline {
public:
	std::map<int, Itime> events;
};

class Renderer {
private:
	std::vector<Primitive*> primitives;
public:
	int current_id = 1;
	float start_time = 0;

	void submit(Primitive* prim);
	void draw(sf::RenderTarget* target, Timeline* timeline, float t);
};