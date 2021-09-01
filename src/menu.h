#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>

using namespace sf;

/// Класс меню
/**
* Класс, отвечающий за прорисовку меню
* Имеет несколько текстовых переменных и текстур, которые выводятся на экран
*/
class Menu {
  private:
    Text nametext;       ///< Название игры
    Text startgametext;  ///< "Start game"
    Text exittext;		 ///< "Exit"
    int current;	     ///< Счетчик текущей кнопки
    Font menufont;		 ///< Шрифт текстов
    bool check;			 ///< Логическая переменная, используемая для выхода из меню или закрытия окна.
    Texture menutexture; ///< Текстура заднего фона 
    Sprite backmenu;	 ///< Спрайт для заднего фона 

  public:
    Menu();

	void drawmenu(RenderWindow &window);
};



#endif MENU_H
