#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

using namespace std;

/// Перечисление, содержащее возможные направления движения игрока
enum class Rocketdirection { STOP, DOWN, UP };

/// Класс игрока
/**
 * Имеет методы, позволяющие управлять игроком с помощью клавиатуры и мыши,
 * проверять на выходы из-за границ экрана и т.д.
 */
class Player {
  private:
    const float playerspeed;   ///< Скорость игрока
    Rocketdirection playerdir; ///< Переменная хранящая текущее направление игрока
    Vector2f offset;		   ///< вектор используемый для изменения координат игрока
    int score;				   ///< счет игрока
    RectangleShape rocket;	   ///< Форма игрока
    Texture playertexture;	   ///< Текстура игрока

  public:
    Player();

    void startpos(float r, const unsigned height);

    void setdir(Rocketdirection newdir);

    void setoffset();

    void move(float dt);

    void checkcollision(const unsigned int h);

    void mousecontrol(RenderWindow &wind);

    void setscore();

    RectangleShape getshape();

    int getscore();

	void settexture();

};

#endif
