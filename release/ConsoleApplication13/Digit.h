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

	static void Load_Texture()  // �������� ����� ����� ��������� ��� ���� ����������� �������
	{
		if(!t_digit.loadFromFile("digits.png"))
			std::cout<<"Error loading texture 'digits'"<<std::endl;
	}
	int Get_Digit(); // ������� int-�������� �� ����������� � ������� ��������
	void Draw_Digit(sf::RenderWindow &window);
};
