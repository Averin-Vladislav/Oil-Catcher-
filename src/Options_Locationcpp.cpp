#include < SFML/Graphics.hpp >
#include "Options_Location.h"
#include <iostream>
#include "Game_Manager.h"
#include "Game_Location.h"

Options_Location::Options_Location(sf::RenderWindow& window, Game_Manager* game_manager) : Location(window, game_manager)
{
	select = 1;
	choice_1 = false;
	choice_2 = true;

	if(!t_location.loadFromFile("options.jpg"))
		std::cout<<"Error loading texture 'menu'"<<std::endl;

	setTexture(t_location);
	setTextureRect(sf::IntRect(0, 0, 1366, 768));

	t_true.loadFromFile("true.png");
	t_false.loadFromFile("false.png");

	for (int i = 0; i < 2; i++)
	{
		s_true[i].setTexture(t_true);
		s_true[i].setTextureRect(sf::IntRect(0, 0, 50, 50));
		s_true[i].setPosition(780, 280 + i*(70));

		s_false[i].setTexture(t_false);
		s_false[i].setTextureRect(sf::IntRect(0, 0, 50, 50));
		s_false[i].setPosition(780, 280 + i * 70);
	}

	options_Location_font.loadFromFile("font2.ttf");

	for (int i = 0; i < 3; i++)
	{
		text[i].setFont(options_Location_font);
		text[i].setColor(sf::Color::Black);
	}

	text[0].setPosition(510, 290);
	text[1].setPosition(540, 360);
	text[2].setPosition(650, 430);

	text[0].setColor(sf::Color::Red);

	text[0].setString("Hard Mode");
	text[1].setString("Sound");
	text[2].setString("Back");
}

Options_Location::~Options_Location()
{

}

void Options_Location::Check_Event(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			if (game_manager->isSoundOn == true)
				game_manager->Play_Sound("switch");

			switch(select)
			{
			case 1:
				text[0].setColor(sf::Color::Black);
				text[1].setColor(sf::Color::Black);
				text[2].setColor(sf::Color::Red);

				select = 3;
				break;

			case 2:
				text[0].setColor(sf::Color::Red);
				text[1].setColor(sf::Color::Black);
				text[2].setColor(sf::Color::Black);

				select = 1;
				break;

			case 3:
				text[0].setColor(sf::Color::Black);
				text[1].setColor(sf::Color::Red);
				text[2].setColor(sf::Color::Black);
	
				select = 2;
				break;
			}
			break;

		case sf::Keyboard::Down:
			if (game_manager->isSoundOn == true)
				game_manager->Play_Sound("switch");

			switch(select)
			{
			case 1:
				
				text[0].setColor(sf::Color::Black);
				text[1].setColor(sf::Color::Red);
				text[2].setColor(sf::Color::Black);

				select = 2;
				break;

			case 2:
				text[0].setColor(sf::Color::Black);
				text[1].setColor(sf::Color::Black);
				text[2].setColor(sf::Color::Red);

				select = 3;
				break;

			case 3:
				text[0].setColor(sf::Color::Red);
				text[1].setColor(sf::Color::Black);
				text[2].setColor(sf::Color::Black);

				select = 1;
				break;
			}
			break;

		case sf::Keyboard::Return:  
			switch(select)
			{
			case 1:
				if (game_manager->isSoundOn == true)
					game_manager->Play_Sound("select");

				if (choice_1 == false) // включение/отключение режима повышенной сложности
				{
					choice_1 = true;
					game_manager->game.Set_Game_Mode(true);
				}
				else 
				{
					choice_1 = false;
					game_manager->game.Set_Game_Mode(false);
				}
				break;

			case 2:
				game_manager->Play_Sound("select");

				if (choice_2 == false) // включение/отключение звука в игре
				{
					game_manager->isSoundOn = true;
					game_manager->sound.Menu(false);
					choice_2 = true;
				}
				else 
				{
					game_manager->isSoundOn = false;
					game_manager->sound.Menu(true);
					choice_2 = false;
				}
				break;

			case 3: // выход из локации настроек игры
				if (game_manager->isSoundOn == true)
					game_manager->Play_Sound("enter");

				game_manager->Set_Active_Location(STARTLOCATION);
				game_manager->previousLocation = &game_manager->options;
				break;
			}
			break;
		}
}

void Options_Location::Draw()
{
	Location::Draw();

	for (int i = 0; i < 3; i++)
		window.draw(text[i]);

	if (choice_1 == true) 
		window.draw(s_true[0]);
	else 
		window.draw(s_false[0]);
	
	if (choice_2 == true) 
		window.draw(s_true[1]);
	else
		window.draw(s_false[1]);
}



