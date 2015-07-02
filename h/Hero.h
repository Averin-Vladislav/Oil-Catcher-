#pragma once

#include < SFML/Graphics.hpp >
#include "Hero_Digit.h"

class Hero: public sf::Sprite
{
	int Hero_Status; // какой кадр активен (необходимо для анимации)

	sf::Texture t_hero;

	sf::Clock clock;
	sf::Time time;

public:

	Hero();
	~Hero();

	void Hero_Animation();
	void Draw_Hero(sf::RenderWindow &window);
};

