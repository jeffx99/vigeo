#include "primitive.hpp"
#include "renderer.hpp"

Renderer* Primitive::renderer;
Primitive::Primitive() {
	renderer->submit(this);
}
