#include <algorithm>
#include <iostream>
#include "path.hpp"
#include "geo.hpp"

void Path::draw(sf::RenderTarget * target, float t) {
	for (int i = 0; i < subpaths.size(); ++i) {
		sf::VertexArray subpath_array(sf::TriangleStrip);

		/* Calculate the total distance traversed by the path */
		float total_distance = distance(i);

		// current distance traversed by pen
		float current_dist = 0;
		float overshoot = 0;
		int index;
		for (index = 1; index < subpaths[i].size(); ++index) {
		    Coord delta = subpaths[i][index] - subpaths[i][index - 1];
			float sublength = length(delta);
			current_dist += sublength;
			if (current_dist > total_distance * t) { // if the current distance exceeds the theoretical
				overshoot = sublength;
				break;
			}
			// When loop ends index should be the size if it did not break
		}
		
		// draw the path up to the index before the interpolated segment
		draw_path(i, index, subpath_array);

		// happens also when index = size
		if (overshoot != 0) {
			// Interpolation factor
			float k = 1 - (current_dist - total_distance * t) / overshoot;
			draw_interp(i, index, k, subpath_array);
		}

		target->draw(subpath_array);
	}
}

float Path::distance(int i) {
	float distance = 0;
	for (int j = 1; j < subpaths[i].size(); ++j) {
		Coord delta = subpaths[i][j] - subpaths[i][j - 1];
		distance += length(delta);
	}

	return distance;
}

void Path::draw_path(int i, int index, sf::VertexArray& subpath_array) {
	for (int j = 0; j < index; ++j) {
		/* Calculate offset vector
		- get position of (i-1)th, this, and (i+1)th point, p1, p2, p3 (if it exists)
		- if p1 doesn't exist set p1 = p2, likewise if p3 doesn't exist set p3 = p2
		- do ((p1-p2) + (p2-p3)) = (p1 - p3) to get approximate tangent vector
		- get perpendicular vector to the tangent
		- scale
		*/

		Coord p1, p2, p3;
		Vector normal;
		p1 = subpaths[i][std::max(j - 1, 0)];
		p2 = subpaths[i][j];
		p3 = subpaths[i][std::min((int)subpaths[i].size() - 1, j + 1)];
		normal = perp(p1 - p3);
		float norm_length = length(normal);
		if (norm_length != 0) {
			normal /= norm_length;
			normal *= 0.5f * thickness * SCREEN_TO_PLANE;
		}
		else {
			normal *= 0.f;
		}

		//std::cout << perp.x;
		// Draw vertices
		subpath_array.append(sf::Vertex(plane_to_screen(p2 - normal), colors[i % colors.size()]));
		subpath_array.append(sf::Vertex(plane_to_screen(p2 + normal), colors[i % colors.size()]));
	}
}

void Path::draw_interp(int i, int index, float k, sf::VertexArray& subpath_array) {
	Coord p1, p2;
	p1 = subpaths[i][index - 1];
	p2 = subpaths[i][index];
	Coord interpolated = p1 + k * (p2 - p1);

	// One last offset

	Vector normal = perp(p1 - p2);
	float norm_length = length(normal);
	if (norm_length != 0) {
		normal /= norm_length;
		normal *= 0.5f * thickness * SCREEN_TO_PLANE;
	}
	else {
		normal *= 0.f;
	}

	subpath_array.append(sf::Vertex(plane_to_screen(interpolated - normal), colors[i % colors.size()]));
	subpath_array.append(sf::Vertex(plane_to_screen(interpolated + normal), colors[i % colors.size()]));
}

