#include < SFML/Graphics.hpp >
#include "Digit.h"

#pragma once

class Score_Digit: public Digit
{

public:

	Score_Digit();
	~Score_Digit();

	void Change_Score_Digit();
	void Set_Pos_Digit(float pos_x, float pos_y);
	void Draw_Score_Digit(sf::RenderWindow &window);
};