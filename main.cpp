#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "point.hpp"
#include "segment.hpp"
#include "circle.hpp"
#include "geo.hpp"
#include "renderer.hpp"

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
	
	Coord A(450, 350);
	Coord B(200, 175);
	Coord C(550, 150);

	
	Coord D = project(A, B, C);
	Coord M = (A + B) / 2, N = (A + C) / 2;
	Coord L = (B + C) / 2 + perp(B, C);

	Coord Bp = reflect(B, D, M), Cp = reflect(C, D, N);
	Coord Ap = reflect(A, (B + C) / 2, L);

	Coord O = circumcenter(Ap, Bp, Cp);
	Coord O1 = circumcenter(A, B, D);
	Coord O2 = circumcenter(A, C, D);


	renderer.current_id = 1;
	Point pA(A);
	Segment AB(A, B);
	renderer.current_id = 2;
	Segment BC(B, C);
	renderer.current_id = 3;
	Segment CA(C, A);
	renderer.current_id = 4;
	Tick tAM(A, M, 1);
	Tick tMB(M, B, 1);
	Tick tAN(A, N, 2);
	Tick tNC(N, C, 2);

	Point pD(D);
	Point pM(M);
	Point pN(N);
	//Point pN(N);
	Segment AD(A, D);
	renderer.current_id = 5;
	Line DM(D, M);
	Line DN(D, N);
	renderer.current_id = 6;
	Point pBp(Bp);
	Segment BBp(B, Bp);
	renderer.current_id = 7;
	Point pCp(Cp);
	Segment CCp(C, Cp); 
	renderer.current_id = 8;
	Line l((B + C) / 2, L);
	Point pAp(Ap);
	renderer.current_id = 9;
	Segment AAp(A, Ap);
	renderer.current_id = 10;
	Point pO(O);
	Circle ApBpCp(O, Ap);
	renderer.current_id = 11;
	Line ABp(A, Bp);
	Line ACp(A, Cp);
	Point pO1(O1);
	Circle ABD(O1, D);
	Point pO2(O2);
	Circle ACD(O2, D);


	{/*Coord D, E, F, Oa, Ob, Oc;
	D = (2 * B + C) / 3;
	E = (3 * A + C) / 4;
	F = (A + B) / 2;

	Oa = circumcenter(A, E, F);
	Ob = circumcenter(B, D, F);
	Oc = circumcenter(C, D, E);

	renderer.current_id = 1;
	Segment(A, B);
	Segment BC(B, C);
	Segment CA(C, A);

	renderer.current_id = 2;
	Segment DE(D, E);
	Segment EF(E, F);
	Segment FD(F, D);


	renderer.current_id = 3;
	Circle AEF(Oa, A);
	Circle BDF(Ob, B);
	Circle CDE(Oc, C);*/}

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