#include "ball.h"
#include "player.h"
#include "menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

const unsigned width = 900;  ///< Ширина окна
const unsigned height = 600; ///< Высота окна

/// Функция, устанавливающая в начальные положения игроков и мяч
void startpos(Player &player1, Player &player2, Ball &ball) {
    player1.startpos(50.f, height);
    player2.startpos(850.f, height);
    ball.startpos(width, height);
}

/// Функция перезапускающая время в секундах и присваивающая полученное значение переменной
void resettime(float &dt, Clock &gametime) {
    dt = gametime.restart().asSeconds();
}

/// Функция обновляющая текст в соответствии с текущим счетом одного из игроков
void updatetext(Text &text, Player &player) {
    stringstream ss;
    ss << "Score: " << player.getscore();  

    text.setString(ss.str());
}

/**
Функция отвечающая за соударение мяча об игроков.
Также меняет счет игроков
Принимает на вход ссылки на экземпляры классов Ball, Player и Text
*/
void playerhit(Player &player1, Player &player2, Ball &ball, Text &player1text,
               Text &player2text) {

    if (ball.getballshape().getGlobalBounds().intersects(
            player1.getshape().getGlobalBounds())) {
        ball.setballdir(static_cast<Balldirection>(ball.random(4, 6)));
    }

    if (ball.getballshape().getGlobalBounds().intersects(
            player2.getshape().getGlobalBounds())) {
        ball.setballdir(static_cast<Balldirection>(ball.random(1, 3)));
    }

    if ((ball.getballshape().getPosition().x < 0.f)) {
        startpos(player1, player2, ball);
        player2.setscore();
        updatetext(player2text, player2);
    }

    if ((ball.getballshape().getPosition().x > width)) {
        startpos(player1, player2, ball);
        player1.setscore();
        updatetext(player1text, player1);
    }
}

/// Устанавливает параметры текста для счета игрока
void settext(Text &text, Font &font) {
    text.setFont(font);
    text.setString("Score: 0");
    text.setCharacterSize(24);
    text.setFillColor(Color::White);
}

int main() {
    RenderWindow window(VideoMode(width, height), "Ping pong");

    window.setFramerateLimit(60);

	/// Экземпляр класса Menu
	Menu menu;
    menu.drawmenu(window);

    Player player1; ///< Игрок 1 
    Player player2; ///< Игрок 2
    Ball ball;	    ///< Мяч
    startpos(player1, player2, ball);

	float dt; ///< Переменная используемая для привязки изменения координат мяча и игроков ко времени

    Clock gametime; ///< Переменная для измерения прошедшего времени

	/// Шрифт текста
    Font font;
    font.loadFromFile("C:/Gaz.ttf");

	/// Текст для счета первого игрока
    Text player1text;
    settext(player1text, font);

	/// Текст для счета второго игрока
    Text player2text;
    settext(player2text, font);
    player2text.setPosition(815.f, 0.f);
   
	Texture backtexture; ///< Текстура для заднего фона
    Sprite background;   ///< Спрайт для заднего фона
    backtexture.loadFromFile("C:/background.png");
	background.setTexture(backtexture);

    srand(static_cast<unsigned int>(time(0)));

    while (window.isOpen()) {
        resettime(dt, gametime);
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case Event::Closed:
                window.close();
                break;
            }
        }
        
        player1.setoffset();
        player1.move(dt);
        player1.checkcollision(height);

        player2.mousecontrol(window);
        player2.checkcollision(height);

        ball.setballoffset();
        ball.bounce(height);
        ball.moveball(dt);
        
        playerhit(player1, player2, ball, player1text, player2text);

        window.clear();

        window.draw(background);

        window.draw(ball.getballshape());
        window.draw(player1.getshape());
        window.draw(player2.getshape());
        window.draw(player1text);
        window.draw(player2text);

        window.display();
    }
    return 0;
}