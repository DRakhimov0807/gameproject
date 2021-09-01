#include "menu.h"
#include <SFML/Graphics.hpp>

/*!
Конструктор по умолчанию, настраивающий весь текст в меню и задний фон
*/
Menu::Menu() {
    current = 0;
    check = 1;

    menufont.loadFromFile("C:/Gaz.ttf");

    menutexture.loadFromFile("C:/menu.png");
    backmenu.setTexture(menutexture);

    nametext.setFont(menufont);
    nametext.setCharacterSize(36);
    nametext.setFillColor(Color::White);
    nametext.setString("Ping Pong game");
    nametext.setPosition(300.f, 50.f);

    startgametext.setFont(menufont);
    startgametext.setCharacterSize(24);
    startgametext.setFillColor(Color::Blue);
    startgametext.setString("Srart game");
    startgametext.setPosition(300.f, 150.f);

    exittext.setFont(menufont);
    exittext.setCharacterSize(24);
    exittext.setFillColor(Color::White);
    exittext.setString("Exit");
    exittext.setPosition(300.f, 250.f);
}

/*!
Метод, прорисовывающий все меню.
Данный метод также проверяет нажатие клавиш и запускает игру или закрывает окно.
\param window ссылка на переменную типа RenderWindow
*/
void Menu::drawmenu(RenderWindow &window) {
    while (check) {
        window.clear();
		if (Keyboard::isKeyPressed(Keyboard::W) && current == 1) {
			--current;
			startgametext.setFillColor(Color::Blue);
            exittext.setFillColor(Color::White);
		}

		if (Keyboard::isKeyPressed(Keyboard::S) && current == 0) {
			++current;
			exittext.setFillColor(Color::Blue);
            startgametext.setFillColor(Color::White);
		}

		if (Keyboard::isKeyPressed(Keyboard::Enter)) {
			if (current == 0)
				check = 0;
			if (current == 1){
				check = 0;
				window.close();
				}
		}
    window.draw(backmenu);
    window.draw(nametext);
    window.draw(startgametext);
    window.draw(exittext);
    window.display();
	}
}

