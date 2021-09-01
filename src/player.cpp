#include "player.h"
#include <SFML/Graphics.hpp>

/// Конструктор по умолчанию, задающий значения для скорости игрока, размеров, направления движения и текстуры
Player::Player() : playerspeed(300.f) {
    playerdir = Rocketdirection::STOP;
    rocket.setSize(Vector2f(10.f, 45.f));
    score = 0;
    settexture();
}

/// Сеттер для счета игрока
void Player::setscore() { score++; }

/*!
Метод возвращающий игрока в исходное положение
\param r произвольное число
\param height высота окна
*/
void Player::startpos(float r, const unsigned height) {
    rocket.setPosition(r, height / 2);
}

/// Сеттер для направления движения игрока
void Player::setdir(Rocketdirection newdir) { playerdir = newdir; }

/// Сеттер для вектора offset
void Player::setoffset() {
    offset.x = 0.f;
    offset.y = 0.f;
}

/*!
Метод проверяющий нажатие определенных клавиш и меняющий направление движения игрока 
в соответствии с нажатой клавишой.
Также здесь меняется положение игрока.
*/
void Player::move(float dt) {

    if (Keyboard::isKeyPressed(Keyboard::W)) {
        setdir(Rocketdirection::UP);
    }

    if (Keyboard::isKeyPressed(Keyboard::S)) {
        setdir(Rocketdirection::DOWN);
    }
    switch (playerdir) {
    case Rocketdirection::UP:
        offset.y -= playerspeed * dt;
        break;
    case Rocketdirection::DOWN:
        offset.y += playerspeed * dt;
        break;
    case Rocketdirection::STOP:
        break;
    default:
        break;
    }
    setdir(Rocketdirection::STOP);
    rocket.move(offset);
}

/*!
Метод проверяющий на столкновение с границами окна
\param h высота окна
*/
void Player::checkcollision(const unsigned int h) {
    if (rocket.getPosition().y < 0.f)
        rocket.setPosition(rocket.getPosition().x, 0.f);

    if (rocket.getPosition().y + rocket.getGlobalBounds().height > h)
        rocket.setPosition(rocket.getPosition().x,
                           h - rocket.getGlobalBounds().height);
}

/*!
Метод позволяющий контролировать положение игрока с помощью мыши
\param window ссылка на переменную типа RenderWindow
*/
void Player::mousecontrol(RenderWindow &window) {
    rocket.setPosition(rocket.getPosition().x, Mouse::getPosition(window).y);
}

/// Геттер для формы игрока
RectangleShape Player::getshape() { return rocket; }

/// Геттер для счета игрока
int Player::getscore() { return score; }

/// Сеттер для текстуры игрока
void Player::settexture() {
    playertexture.loadFromFile("C:/Moon.png");
    rocket.setTexture(&playertexture);
    playertexture.setSmooth(true);
}