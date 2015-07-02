#include "Hero_Digit.h"
#include "Oil_Digit.h"

Hero_Digit::Hero_Digit()
{
	std::srand(std::time(NULL));

	for(int i = 0; i < 9; ++i)
	{
		hero_digit_map.insert(std::make_pair(sf::Keyboard::Key(sf::Keyboard::Num1 + i), i + 1)); 
		hero_digit_map.insert(std::make_pair(sf::Keyboard::Key(sf::Keyboard::Numpad1 + i), i + 1)); 
	}
	number = std::rand() % 9 + 1; // первая цифра устанавливается случайным образом

	setTexture(t_digit);
	setTextureRect(sf::IntRect(((number + 2) % 3) * 100, ((number - 1) / 3) * 100, 100, 100)); // формула опреденения координаты
																							   // цифры по ее int-значению
	setPosition(610, 275);
}

Hero_Digit::~Hero_Digit()
{

}

void Hero_Digit::Change_Hero_Digit(sf::Event event)
{
	if((event.key.code >= sf::Keyboard::Numpad1 && event.key.code <= sf::Keyboard::Numpad9)
	|| (event.key.code >= sf::Keyboard::Num1 && event.key.code <= sf::Keyboard::Num9))
	{
		number = hero_digit_map[event.key.code];
		setTextureRect(sf::IntRect(((number + 2) % 3) * 100, ((number - 1) / 3) * 100, 100, 100));
	}
}

void Hero_Digit::Draw_Hero_Digit(sf::RenderWindow &window)
{
	Digit::Draw_Digit(window);
}
