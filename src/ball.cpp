#include "ball.h"
#include "player.h"
#include <SFML/Graphics.hpp>

/// Конструктор по умолчанию, задающий значения для скорости мяча, радиуса, направления движения и текстуры
Ball::Ball() : ballspeed(600.f) {
    ballshape.setRadius(20.f);
    balldir = Balldirection::LEFT;
    ballshape.setOrigin(20.f, 20.f);
    settexture();
}

/*!
Метод, проверяющий на соударение мяча об границы окна и изменяющий направление движения после.
\param height высота окна
*/
void Ball::bounce(const unsigned int height) {
	if (ballshape.getPosition().y - ballshape.getRadius() < 0.f) {
		ballshape.setPosition(ballshape.getPosition().x,
			0.f + ballshape.getRadius());

		if (balldir == Balldirection::UPRIGHT) {
			setballdir(Balldirection::DOWNRIGHT);
		}

		if (balldir == Balldirection::UPLEFT) {
			setballdir(Balldirection::DOWNLEFT);
		}
	}

	if (ballshape.getPosition().y + ballshape.getRadius() > height) {
		ballshape.setPosition(ballshape.getPosition().x,
			height - ballshape.getRadius());

		if (balldir == Balldirection::DOWNRIGHT) {
			setballdir(Balldirection::UPRIGHT);
		}

		if (balldir == Balldirection::DOWNLEFT) {
			setballdir(Balldirection::UPLEFT);
		}
	}
}

/// Сеттер для направления движения мяча
void Ball::setballdir(Balldirection newbdir) { balldir = newbdir; }

/*!
Метод генерирующий случайное значение в определенном диапазоне (заимствовано)
\param min минимальное число диапазона
\param max максимальное число диапазона
*/
int Ball::random(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

/// Метод меняющий координаты вектора balloffset и положение мяча в соответствии с его текущим направлением движения
void Ball::moveball(float dt) {
    switch (balldir) {
    case Balldirection::LEFT:
        balloffset.x -= ballspeed * dt;
        break;
    case Balldirection::DOWNLEFT:
        balloffset.x -= ballspeed * dt;
        balloffset.y += ballspeed * dt;
        break;
    case Balldirection::UPLEFT:
        balloffset.x -= ballspeed * dt;
        balloffset.y -= ballspeed * dt;
        break;
    case Balldirection::RIGHT:
        balloffset.x += ballspeed * dt;
        break;
    case Balldirection::DOWNRIGHT:
        balloffset.x += ballspeed * dt;
        balloffset.y += ballspeed * dt;
        break;
    case Balldirection::UPRIGHT:
        balloffset.x += ballspeed * dt;
        balloffset.y -= ballspeed * dt;
        break;
    case Balldirection::STOP:
        break;
    default:
        break;
    }
    ballshape.move(balloffset);
}

/// Геттер для формы мяча
CircleShape Ball::getballshape() { return ballshape; }

/// Сеттер для вектора balloffset
void Ball::setballoffset() {
    balloffset.x = 0;
    balloffset.y = 0;
}

/*!
Метод возвращающий мяч в исходное положение
\param width ширина окна
\param height высота окна
*/
void Ball::startpos(const unsigned int width, const unsigned int height) {
    ballshape.setPosition(width / 2, height / 2);
    setballdir(Balldirection::LEFT);
}

/// Сеттер для текстуры мяча
void Ball::settexture() {
    balltexture.loadFromFile("C:/sun.png");
    ballshape.setTexture(&balltexture);
    balltexture.setSmooth(true);
}

