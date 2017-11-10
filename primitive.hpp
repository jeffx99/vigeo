#pragma once
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>

class Renderer;
struct Itime {
public:
	float start_t = -1, end_t = 0;
	Itime() {};
	Itime(float st, float et) : start_t(st), end_t(et) {}

	bool contains(float& t) {
		return (start_t <= t);
	}

	float completion(float t) {
		return fminf(1, (t - start_t) / (end_t - start_t));
	}
};


class Primitive {
public:
	static Renderer* renderer;

	int draw_id; // used for placing in interval
	bool auxiliary = false; // will this be drawn?

	Primitive();
	virtual ~Primitive() {};
	virtual void draw(sf::RenderTarget* target, float k) = 0;
};