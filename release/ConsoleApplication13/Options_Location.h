#pragma once

#include < SFML/Graphics.hpp >
#include <iostream>
#include "Location.h"

class Game_Manager;

class Options_Location: public Location
{
	sf::Font options_Location_font; // �����
	sf::Text text[3];

	sf::Texture t_true;   // ������� � 
	sf::Texture t_false;  // ������� ��� ����������� ��������/���������
	sf::Sprite  s_true[2];
	sf::Sprite  s_false[2];
	
	bool choice_1; // ����� ������ � 
	bool choice_2; // ������ ���������

	int select; // ����� ������ � ���� �������� �������

public:

	Options_Location(sf::RenderWindow& window, Game_Manager* game_manager);
	~Options_Location();

	void Check_Event(const sf::Event& event);
	void Draw();
};