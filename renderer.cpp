#include "renderer.hpp"
#include <iostream>

void Renderer::submit(Primitive* prim) {
	prim->draw_id = current_id;
	primitives.push_back(prim);
}

void Renderer::draw(sf::RenderTarget* target, Timeline* timeline, float t) {
	t -= start_time;
	for (int i = primitives.size() - 1; i >= 0; --i) {
		if (primitives[i]->auxiliary || primitives[i] == nullptr) {
			primitives.erase(primitives.begin() + i);
		}
	}

	for (auto primitive : primitives) {
		Itime interval = timeline->events.at(primitive->draw_id);
		if (interval.contains(t)) {
			float k = interval.completion(t);
			primitive->draw(target, k);
		}
	}
}
