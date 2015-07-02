#pragma once

#include "Location.h"
#include < SFML/Graphics.hpp >
#include <iostream>

class Game_Manager;

class Exit_Location: public Location
{
	sf::Font exit_location_font; // ����� ������ � ������� ������
	sf::Text text[3]; // 3 ��������� ������

	bool select; // ���������� ��� �������� ��������� ������

public:

	Exit_Location(sf::RenderWindow& window, Game_Manager* game_manager);
	~Exit_Location();

	void Check_Event(const sf::Event& event);
	void Draw();
};