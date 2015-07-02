#pragma once

#include < SFML/Graphics.hpp >
#include "Score_Digit.h"
#include <string>

class Score: public sf::Sprite
{
	sf::Texture t_score;

	std::string score_string; // ������ � �������� ���-��� �����
	sf::Text score_text;
	sf::Font score_font;

	int result; // int-�������� ����������

public:

	Score();
	~Score();

	void Add_Point();
	void Set_Score(std::string start_value);
	std::string Get_Score();
	void Draw_Score(sf::RenderWindow &window);
};
