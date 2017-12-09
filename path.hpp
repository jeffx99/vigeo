#pragma once
#include <vector>
#include "primitive.hpp"
#include "coord.hpp"

using std::vector;

/* 
	Describes the mode a path is drawn in. 
*/
enum PathMode {
	SERIES,
	PARALLEL
};

/* 
	A Path contains subpaths which contain points. 
	Each of these subpaths are drawn either at the
	same time or one after the other. The speed at
	which the curve is drawn at is dependent on 
	the spacing of the points. The drawing
	mechanism in its linear mode will draw 
	each segment in the same amount of time. 
	Thus you should ensure a spacing of points 
	with equal distance (if you want constant 
	speed).	Subclassed by almost all line-drawing 
	classes (Line, Segment,	Tick, Circle, etc.).
*/
class Path : public Primitive {
public:
	vector<vector<Coord>> subpaths;
	vector<sf::Color> colors; // Colors for each subpath.
	PathMode mode = PARALLEL;
	float thickness = 2.0f; // How thick the path lines are. A calculation of the normal is used to create thickness.


	virtual ~Path() {};
	void draw(sf::RenderTarget* target, float t);

private: 
	// get total distance of path i
	float distance(int i);
	// draw the portion of the path i up to index
	void draw_path(int i, int index, sf::VertexArray& subpath_array);
	// draw the interpolation of path i between index and index - 1 with factor k
	void draw_interp(int i, int index, float k, sf::VertexArray& subpath_array);
};