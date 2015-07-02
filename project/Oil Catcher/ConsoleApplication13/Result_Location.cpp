#include < SFML/Graphics.hpp >
#include "Result_Location.h"
#include <iostream>
#include <cstdlib>
#include <string.h>
#include "Game_Manager.h"

Result_Location::Result_Location(sf::RenderWindow& window, Game_Manager* game_manager) : Location(window, game_manager)
{
	if(!Location::t_location.loadFromFile("result.jpg"))
		std::cout<<"Error loading texture 'result'"<<std::endl;

	setTexture(t_location);
	setTextureRect(sf::IntRect(0, 0, 1366, 768));

	result_loation_font.loadFromFile("font.ttf");

	for (int i = 0; i < 3; i++)
	{
		text[i].setFont(result_loation_font);
		text[i].setColor(sf::Color::Red);
		text[i].setPosition(500, 300 + (i * 50));
	}

	for (int i = 0; i < 3; i++)
	{
		total[i].setFont(result_loation_font);
		total[i].setColor(sf::Color::Black);
		total[i].setPosition(720, 300 + (i * 50));
	}

	text[0].setString("Your score:");
	text[1].setString("Your time:");
	text[2].setString("Bonus Drops:");
}

Result_Location::~Result_Location()
{
	
}

void Result_Location::Set_Score(std::string result_score, std::string result_time, std::string result_drops)
{
	total[0].setString(result_score); // итоговый счет
	total[1].setString(result_time.assign(result_time, 0, 5)); // отоговое время игры
	total[2].setString(result_drops); // кол-во "пойманых" особых капель
}

void Result_Location::Check_Event(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed) // при нажатии любой клавиши осуществляется выход их локации результата
		if(sf::Keyboard::isKeyPressed)
		{
			if (game_manager->isSoundOn == true)
			{
				game_manager->Play_Sound("enter");
				game_manager->Play_Music("menu", false);
			}
			game_manager->Set_Active_Location(STARTLOCATION);
			game_manager->previousLocation = &game_manager->result;
		}
}

void Result_Location::Draw()
{
	Location::Draw();

	for (int i = 0; i < 3; i++)
		window.draw(text[i]);
	for (int i = 0; i < 3; i++)
		window.draw(total[i]);
}


