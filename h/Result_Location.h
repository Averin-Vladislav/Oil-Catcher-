#pragma once

#include < SFML/Graphics.hpp >
#include <iostream>
#include "Location.h"

class Result_Location: public Location
{
	sf::Font result_loation_font; // шрифт
	sf::Text text[3];
	sf::Text total[3]; // конечные результаты

public:

	Result_Location(sf::RenderWindow& window, Game_Manager* game_manager);
	~Result_Location();

	void Set_Score(std::string result_score, std::string result_time, std::string result_drops);
	void Check_Event(const sf::Event& event);
	void Draw();
};
