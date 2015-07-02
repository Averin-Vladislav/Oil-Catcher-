#include "Digit.h"
#include <iostream>
#include <string>

sf::Texture Digit::t_digit;

Digit::Digit()
{
	setTexture(t_digit);

	start_pos_x = 100;
	start_pos_y = 100;

	setPosition(start_pos_x, start_pos_y);
}

Digit::~Digit()
{

}

int Digit::Get_Digit()
{
	return number;
}

void Digit::Draw_Digit(sf::RenderWindow &window)
{
	window.draw(*this);
}



