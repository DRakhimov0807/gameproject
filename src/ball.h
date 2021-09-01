#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

using namespace sf;

/// Перечисление, содержащее возможные направления движения мяча
enum class Balldirection {
    STOP,
    LEFT,
    UPLEFT,
    DOWNLEFT,
    RIGHT,
    UPRIGHT,
    DOWNRIGHT,

};

/// Класс мяча
/**
 * Содержит методы, определяющие поведение мяча.
 * Также имеет переменные хранящие скорость мяча, текстуру и т.д
 */
class Ball {
  private:
    const float ballspeed; ///< Скорость движения мяча
    Vector2f balloffset;   ///< вектор используемый для изменения координат мяча
    CircleShape ballshape; ///< Форма мяча
    Balldirection balldir; ///< переменная, хранящая текущее направление мяча
    Texture balltexture;   ///< Текстура мяча

  public: 
    Ball();

    void bounce(const unsigned int height);

    void setballdir(Balldirection newbdir);

    int random(int min, int max);

    void moveball(float dt);

    CircleShape getballshape();

    void setballoffset();

    void startpos(const unsigned int width, const unsigned int height);

	void settexture();

};

#endif 
