#include "Hero.h"
#include <iostream>

#define ANIMATION_SPEED 0.1

Hero::Hero()
{
	if(!t_hero.loadFromFile("hero.png"))
		std::cout<<"Error loading texture 'hero'"<<std::endl;

	setTexture(t_hero);
	setTextureRect(sf::IntRect(0, 0, 200, 300));
	setPosition(600, 60);

	clock.restart();

	time = sf::seconds(ANIMATION_SPEED); // скорость анимации
	Hero_Status = 1; // анимация начинается с первого кадра
}

Hero::~Hero()
{

}

void Hero::Hero_Animation()
{
	if (clock.getElapsedTime() > time) // смена кадров
	{
		switch (Hero_Status)
		{
		case 1:
			setTextureRect(sf::IntRect(200, 0, 200, 300));
			Hero_Status = 2;
			break;

		case 2:
			setTextureRect(sf::IntRect(400, 0, 200, 300));
			Hero_Status = 3;
			break;

		case 3:
			setTextureRect(sf::IntRect(0, 0, 200, 300));
			Hero_Status = 1;
			break;
		}
		clock.restart();	
	}
}

void Hero::Draw_Hero(sf::RenderWindow &window)
{
	window.draw(*this);
}



