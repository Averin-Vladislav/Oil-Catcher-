#pragma once

#include < SFML/Graphics.hpp >
#include "Digit.h"

class Hero_Digit: public Digit
{
	std::map<sf::Keyboard::Key, int> hero_digit_map; // карта соответствий кодов клавиш и int-значений цифр

public:

	Hero_Digit();
	~Hero_Digit();

	void Change_Hero_Digit(sf::Event event); // изменения цифры в зависимости от нашатой клавиши
	void Draw_Hero_Digit(sf::RenderWindow &window);
};