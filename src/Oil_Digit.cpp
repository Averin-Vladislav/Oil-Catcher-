#include "Oil_Digit.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

Oil_Digit::Oil_Digit()
{
	Change_Oil_Digit(sf::Time());

	setTexture(t_digit);
	setPosition(start_pos_x, start_pos_y);

	clock.restart();
}

Oil_Digit::~Oil_Digit()
{

}

void Oil_Digit::Set_Oil_Digit_Position(float x, float y)
{
	setPosition(x, y);
}

void Oil_Digit::Change_Oil_Digit(sf::Time time)
{
	if (clock.getElapsedTime() > time) // если прошло заданное время смены цифры, меням ее на случайную
	{
		number = std::rand()% 9 + 1;
		
		setTextureRect(sf::IntRect(((number + 2) % 3) * 100, ((number - 1) / 3) * 100, 100, 100));

		clock.restart();
	}
}

sf::Time Oil_Digit::Get_Time()
{
	return clock.getElapsedTime();
}

void Oil_Digit::Draw_Oil_Digit(sf::RenderWindow &window)
{
	Digit::Draw_Digit(window);
}