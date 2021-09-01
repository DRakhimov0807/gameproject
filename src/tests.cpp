#include "catch.hpp"
#include "ball.h"
#include "player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

TEST_CASE("TEST BALL STARTPOS") {
	Ball b1;
	b1.startpos(900, 600);
	REQUIRE(b1.getballshape().getPosition().x == 450);
	REQUIRE(b1.getballshape().getPosition().y == 300);

	b1.startpos(0, 0);
	REQUIRE(b1.getballshape().getPosition().x == 0);
	REQUIRE(b1.getballshape().getPosition().y == 0);

	b1.startpos(3, 9);
	REQUIRE(b1.getballshape().getPosition().x == 1);
	REQUIRE(b1.getballshape().getPosition().y == 4);
}

TEST_CASE("TEST BALL BOUNCE") {
	Ball b2;
	const unsigned int h = 400;

	b2.startpos(800, 800);
	b2.bounce(h);
	REQUIRE(b2.getballshape().getPosition().y == h - b2.getballshape().getRadius());
	REQUIRE(b2.getballshape().getPosition().x == 400);

	b2.startpos(0, 0);
	b2.bounce(h);
	REQUIRE(b2.getballshape().getPosition().y == b2.getballshape().getRadius());
	REQUIRE(b2.getballshape().getPosition().x == 0.f);
	
}

TEST_CASE("TEST BALL MOVE") {
	Ball b3;
	float dt = 1.f;

	b3.moveball(dt);
	REQUIRE(b3.getballshape().getPosition().x == -600.f);
	REQUIRE(b3.getballshape().getPosition().y == 0.f);

	b3.setballdir(Balldirection::DOWNLEFT);
	b3.moveball(dt);
	REQUIRE(b3.getballshape().getPosition().x == -1800.f);
	REQUIRE(b3.getballshape().getPosition().y == 600.f);

	b3.setballdir(Balldirection::UPLEFT);
	b3.moveball(dt);
	REQUIRE(b3.getballshape().getPosition().x == -3600.f);
	REQUIRE(b3.getballshape().getPosition().y == 600.f);

	b3.setballdir(Balldirection::RIGHT);
	b3.moveball(dt);
	REQUIRE(b3.getballshape().getPosition().x == -4800.f);
	REQUIRE(b3.getballshape().getPosition().y == 600.f);

	b3.setballdir(Balldirection::DOWNRIGHT);
	b3.moveball(dt);
	REQUIRE(b3.getballshape().getPosition().x == -5400.f);
	REQUIRE(b3.getballshape().getPosition().y == 1200.f);

	b3.setballdir(Balldirection::UPRIGHT);
	b3.moveball(dt);
	REQUIRE(b3.getballshape().getPosition().x == -5400.f);
	REQUIRE(b3.getballshape().getPosition().y == 1200.f);
}

TEST_CASE("TEST PLAYER STARTPOS") {
	Player p1;
	p1.startpos(6.f / 3.f, 10.f);
	REQUIRE(p1.getshape().getPosition().x == 2.f);
	REQUIRE(p1.getshape().getPosition().y == 5.f);

	p1.startpos(-1.f * 5.f, 1.f);
	REQUIRE(p1.getshape().getPosition().x == -5.f);
	REQUIRE(p1.getshape().getPosition().y == 0.f);

}

TEST_CASE("TEST PLAYER COLLISION") {
	Player p2;
	const unsigned int h1 = 0;
	
	p2.startpos(0, 0);
	p2.checkcollision(h1);
	REQUIRE(p2.getshape().getPosition().x == 0.f);
	REQUIRE(p2.getshape().getPosition().y == -45.f);

	const unsigned int h2 = 400;
	p2.startpos(0, h2);
	float dt = 1.f;
	p2.setdir(Rocketdirection::UP);
	p2.move(dt);
	p2.checkcollision(h2);
	REQUIRE(p2.getshape().getPosition().x == 0.f);
	REQUIRE(p2.getshape().getPosition().y == 0.f);
}

TEST_CASE("TEST PLAYER MOVE") {
	float dt = 1.f;
	Player p3;

	p3.setdir(Rocketdirection::UP);
	p3.move(dt);
	REQUIRE(p3.getshape().getPosition().y == -300.f);

	p3.setdir(Rocketdirection::DOWN);
	p3.move(dt);
	REQUIRE(p3.getshape().getPosition().y == -300.f);

	p3.setdir(Rocketdirection::DOWN);
	p3.move(dt);
	REQUIRE(p3.getshape().getPosition().y == 0.f);
}
