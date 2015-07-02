#include < SFML/Graphics.hpp >
#include "Score_Digit.h"
#include <iostream>

Score_Digit::Score_Digit()
{
	if(!t_digit.loadFromFile("digits.psd"))
		std::cout<<"Error loading texture 'score_digits'"<<std::endl;

	digit_texture_number_x = 0;
	digit_texture_number_y = 300;

	s_digit.setTexture(t_digit);
	s_digit.setTextureRect(sf::IntRect(digit_texture_number_x, digit_texture_number_y, 100, 100));

	start_pos_x = 540;
	start_pos_y = 0;

	s_digit.setPosition(start_pos_x, start_pos_y);
}

Score_Digit::~Score_Digit()
{

}

void Score_Digit::Change_Score_Digit()
{
	// изменение цифры счета
}

void Score_Digit::Set_Pos_Digit(float pos_x, float pos_y)
{
	s_digit.setPosition(pos_x, pos_y);
}


void Score_Digit::Draw_Score_Digit(sf::RenderWindow &window)
{
	Digit::Draw_Digit(window);
}
