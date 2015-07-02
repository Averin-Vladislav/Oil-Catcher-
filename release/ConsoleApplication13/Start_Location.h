#pragma once

#include < SFML/Graphics.hpp >
#include <iostream>
#include "Location.h"

class Game_Manager;

class Start_Location: public Location
{
	sf::Font start_location_font; // רנטפע
	sf::Text text[3];

	int select;

public:

	Start_Location(sf::RenderWindow& window, Game_Manager* game_manager);
	~Start_Location();

	void Check_Event(const sf::Event& event);
	void Draw();
};