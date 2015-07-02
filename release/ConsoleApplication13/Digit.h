#pragma once

#include < SFML/Graphics.hpp >
#include <iostream>

class Digit: public sf::Sprite
{
protected:

	static sf::Texture t_digit;
	float start_pos_x, start_pos_y;
	int number;

public:
	
	Digit();
	~Digit();

	static void Load_Texture()  // текстура чисел будет одинакова для всех наследуемых классов
	{
		if(!t_digit.loadFromFile("digits.png"))
			std::cout<<"Error loading texture 'digits'"<<std::endl;
	}
	int Get_Digit(); // возврат int-значения по координатам в шаблоне текстуры
	void Draw_Digit(sf::RenderWindow &window);
};
