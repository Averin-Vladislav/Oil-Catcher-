#pragma once

#include < SFML/Graphics.hpp >
#include <iostream>
#include "Location.h"

class Game_Manager;

class Options_Location: public Location
{
	sf::Font options_Location_font; // шрифт
	sf::Text text[3];

	sf::Texture t_true;   // крестик и 
	sf::Texture t_false;  // галочка для обозначения включено/отключено
	sf::Sprite  s_true[2];
	sf::Sprite  s_false[2];
	
	bool choice_1; // выбор первой и 
	bool choice_2; // второй настройки

	int select; // какая строка в меню настроек активна

public:

	Options_Location(sf::RenderWindow& window, Game_Manager* game_manager);
	~Options_Location();

	void Check_Event(const sf::Event& event);
	void Draw();
};