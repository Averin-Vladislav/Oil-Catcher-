#include "Oil_Drop.h"
#include <iostream>

Oil_Drop::Oil_Drop(sf::Texture& texture, sf::Vector2f start_position)
{
	setTexture(texture);
	setTextureRect(sf::IntRect(0, 0, 50, 50));
	setPosition(start_position);
}

Oil_Drop::~Oil_Drop()
{
	
}

DROP Oil_Drop::Get_Type()
{
	return type;
}

void Oil_Drop::Set_Type(DROP Type)
{
	type = Type;
	
	switch (type) // в зависимости от выбранного типа капли, устанавливается ее цвет
	{
	case BAD:
		setColor(sf::Color(212, 0, 0));
		break;

	case NORMAL:
		setColor(sf::Color(0, 0, 0));
		break;

	case GOLD:
		setColor(sf::Color(255, 215, 0));
		break;
	}
}









