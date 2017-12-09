#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "geo.hpp"
#include "renderer.hpp"
#include "segment_paths.hpp"
#include "circle_path.hpp"
#include "point.hpp"

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(960, 540), "Vigeo", sf::Style::Close | sf::Style::Titlebar, settings);
	sf::Clock clock;
	float t = 0;
	
	Timeline timeline;
	Renderer renderer;

	Primitive::renderer = &renderer;

	timeline.events = { // Ignore commentw
		{1, Itime(1.00, 1.33)}, // Triangle
		{2, Itime(1.33, 1.67)},
		{3, Itime(1.67, 2.00)},
		{4, Itime(2, 3)}, // Circles
		{5, Itime(3, 4)}, // Segment OI
		{6, Itime(4, 6)}, // Reflect
		{7, Itime(6, 8)}, // draw segments of reflected OI
		{8, Itime(8, 11)}, // overlay with lines
		{9, Itime(11, 12)}, // dot triangle
		{10, Itime(13, 15)}, // connect second triangle to first
		{11, Itime(15, 16)} // dot the T
	};
	
	Coord A(15, 11);
	Coord B(6.6, 6);
	Coord C(18, 5);

	
	Coord D = project(A, Segment(B, C));
	Coord M = (A + B) / 2, N = (A + C) / 2;
	Coord L = (B + C) / 2 + perp(B - C);

	Coord Bp = reflect(B, Segment(D, M)), Cp = reflect(C, Segment(D, N));
	Coord Ap = reflect(A, Segment((B + C) / 2, L));

	Coord O = circumcenter(Ap, Bp, Cp);
	Coord O1 = circumcenter(A, B, D);
	Coord O2 = circumcenter(A, C, D);


	renderer.current_id = 1;
	Point pA(A);
	SegmentPath AB(A, B);
	renderer.current_id = 2;
	SegmentPath BC(B, C);
	renderer.current_id = 3;
	SegmentPath CA(C, A);
	renderer.current_id = 4;
	Tick tAM(A, M, 1);
	Tick tMB(M, B, 1);
	Tick tAN(A, N, 2);
	Tick tNC(N, C, 2);

	Point pD(D);
	Point pM(M);
	Point pN(N);
	//Point pN(N);
	SegmentPath AD(A, D);
	renderer.current_id = 5;
	LinePath DM(D, M);
	LinePath DN(D, N);
	renderer.current_id = 6;
	Point pBp(Bp);
	SegmentPath BBp(B, Bp);
	renderer.current_id = 7;
	Point pCp(Cp);
	SegmentPath CCp(C, Cp); 
	renderer.current_id = 8;
	LinePath l((B + C) / 2, L);
	Point pAp(Ap);
	renderer.current_id = 9;
	SegmentPath AAp(A, Ap);
	renderer.current_id = 10;
	Point pO(O);
	CirclePath ApBpCp(O, Ap);
	renderer.current_id = 11;
	LinePath ABp(A, Bp);
	LinePath ACp(A, Cp);
	Point pO1(O1);
	CirclePath ABD(O1, D);
	Point pO2(O2);
	CirclePath ACD(O2, D);
	

	
  /*Coord D, E, F, Oa, Ob, Oc;
	D = (2 * B + C) / 3;
	E = (3 * A + C) / 4;
	F = (A + B) / 2;

	Oa = circumcenter(A, E, F);
	Ob = circumcenter(B, D, F);
	Oc = circumcenter(C, D, E);

	renderer.current_id = 1;
	SegmentPath AB(A, B);
	SegmentPath BC(B, C);
	SegmentPath CA(C, A);

	renderer.current_id = 2;
	SegmentPath DE(D, E);
	SegmentPath EF(E, F);
	SegmentPath FD(F, D);


	renderer.current_id = 3;
	CirclePath AEF(Oa, A);
	CirclePath BDF(Ob, B);
	CirclePath CDE(Oc, C);*/

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
		}
		t = clock.getElapsedTime().asSeconds();


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			clock.restart();
		}


		window.clear(sf::Color(10, 10, 10));

		renderer.draw(&window, &timeline, t);

		window.display();
	}
}