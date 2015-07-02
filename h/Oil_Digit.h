#pragma once

#include < SFML/Graphics.hpp >
#include "Digit.h"

class Oil_Digit: public Digit
{
	sf::Clock clock;

public:

	Oil_Digit();
	~Oil_Digit();

	void Change_Oil_Digit(sf::Time time); // принимает частоту замены цифры
	void Set_Oil_Digit_Position(float x, float y);
	sf::Time Get_Time();
	void Draw_Oil_Digit(sf::RenderWindow &window);
};