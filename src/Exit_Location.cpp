#include < SFML/Graphics.hpp >
#include "Exit_Location.h"
#include <iostream>
#include "Game_Manager.h"

Exit_Location::Exit_Location(sf::RenderWindow& window, Game_Manager* game_manager) : Location(window, game_manager)
{
	select = true;

	if(!Location::t_location.loadFromFile("exit.jpg"))
		std::cout<<"Error loading texture 'exit'"<<std::endl;

	setTexture(t_location);
	setPosition(513, 244);
	setTextureRect(sf::IntRect(0, 0, 320, 240));

	exit_location_font.loadFromFile("font.ttf");

	for (int i = 0; i < 3; i++)
	{
		text[i].setFont(exit_location_font);
		text[i].setColor(sf::Color::Black);
	}

	text[0].setString("Are you sure?");
	text[1].setString("Yes");
	text[2].setString("No");

	text[0].setPosition(583,304);
	text[1].setPosition(603,374);
	text[2].setPosition(693,374);
}

Exit_Location::~Exit_Location()
{

}

void Exit_Location::Check_Event(const sf::Event& event) // перемещение по меню выхода
{
	if (event.type == sf::Event::KeyPressed)
		switch (event.key.code)
		{
		case sf::Keyboard::Left:
			if (game_manager->isSoundOn == true)
				game_manager->Play_Sound("switch");

			if(select == true)
			{
				text[1].setColor(sf::Color::Black);
				text[2].setColor(sf::Color::Red);

				select = false;
			}
			else
				{
					text[1].setColor(sf::Color::Red);
					text[2].setColor(sf::Color::Black);
				}
			break;

		case sf::Keyboard::Right:
			if (game_manager->isSoundOn == true)
				game_manager->Play_Sound("switch");

			if(select == true)
			{
				text[1].setColor(sf::Color::Red);
				text[2].setColor(sf::Color::Black);

				select = false;
			}
			else
				{
					text[1].setColor(sf::Color::Black);
					text[2].setColor(sf::Color::Red);
				}
			break;

		case sf::Keyboard::Return:  
			if (game_manager->isSoundOn == true)
				game_manager->Play_Sound("enter");

			if (text[1].getColor() == sf::Color::Red && game_manager->previousLocation == &game_manager->start)
			{
				window.close(); // если выход подтвежден - закрываем окно
			}
			if (text[1].getColor() == sf::Color::Red && game_manager->previousLocation == &game_manager->game)
			{
				if (game_manager->isSoundOn == true)
					game_manager->Play_Music("menu", false);
				game_manager->Set_Active_Location(STARTLOCATION);
				game_manager->previousLocation = &game_manager->exit;
			}
			if (text[2].getColor() == sf::Color::Red && game_manager->previousLocation == &game_manager->start)
			{
				game_manager->Set_Active_Location(STARTLOCATION);
				game_manager->previousLocation = &game_manager->exit;
			}
			if (text[2].getColor() == sf::Color::Red && game_manager->previousLocation == &game_manager->game)
			{
				game_manager->Set_Active_Location(GAMELOCATION);
				game_manager->previousLocation = &game_manager->exit;
			}
			break;
		}
}

void Exit_Location::Draw()
{
	Location::Draw();
	for (int i = 0; i < 3; i++)
		window.draw(text[i]);
}



