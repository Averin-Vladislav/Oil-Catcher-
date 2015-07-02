#pragma once

#include < SFML/Graphics.hpp >
#include "Digit.h"

class Hero_Digit: public Digit
{
	std::map<sf::Keyboard::Key, int> hero_digit_map; // ����� ������������ ����� ������ � int-�������� ����

public:

	Hero_Digit();
	~Hero_Digit();

	void Change_Hero_Digit(sf::Event event); // ��������� ����� � ����������� �� ������� �������
	void Draw_Hero_Digit(sf::RenderWindow &window);
};