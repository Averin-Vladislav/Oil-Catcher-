#include < SFML/Graphics.hpp >
#include "Start_Location.h"
#include <iostream>
#include "Game_Manager.h"
#include "Sound.h"

Start_Location::Start_Location(sf::RenderWindow& window, Game_Manager* game_manager) : Location(window, game_manager)
{
	select = 1;

	if(!t_location.loadFromFile("menu.jpg"))
		std::cout<<"Error loading texture 'menu'"<<std::endl;

	setTexture(t_location);
	setTextureRect(sf::IntRect(0, 0, 1366, 768));

	start_location_font.loadFromFile("font2.ttf");

	for (int i = 0; i < 3; i++)
	{
		text[i].setFont(start_location_font);
		text[i].setColor(sf::Color::Black);
	}

	text[0].setColor(sf::Color::Red);

	text[0].setPosition(640, 310);
	text[1].setPosition(615, 380);
	text[2].setPosition(640, 450);

	text[0].setString("Play");
	text[1].setString("Options");
	text[2].setString("Exit");
}

Start_Location::~Start_Location()
{

}

void Start_Location::Check_Event(const sf::Event& event)
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
			if (game_manager->isSoundOn == true)
				game_manager->Play_Sound("enter");

			switch(select)
			{
			case 1:
				game_manager->game.New_Game();
				game_manager->Play_Music("menu", true);
				game_manager->Set_Active_Location(GAMELOCATION);
				break;

			case 2:
				game_manager->Set_Active_Location(OPTIONSLOCATION);
				break;

			case 3:
				game_manager->Set_Active_Location(EXITLOCATION);		
				break;
			}
			game_manager->previousLocation = &game_manager->start;
			break;
		}
}

void Start_Location::Draw()
{
	Location::Draw();
	for (int i = 0; i < 3; i++)
		window.draw(text[i]);
}



