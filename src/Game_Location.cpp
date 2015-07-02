#include "Game_Location.h"
#include "Score.h"
#include <iostream>
#include "Game_Manager.h"

#define HARD_MODE_OFFSET 0.7
#define NORMAL_MODE_OFFSET 2.0

enum DROP;

Game_Location::Game_Location(sf::RenderWindow& window, Game_Manager* game_manager) : Location(window, game_manager)
{
	hard_mode = false; // режим повышенной сложности отключен
	isDigitsSame = true; 
	gold_drops_amount = 0;
	result_drops = "000";

	if(!t_game_1.loadFromFile("game_2.png"))
		std::cout<<"Error loading texture 'map_1'"<<std::endl;
	if(!t_game_2.loadFromFile("game_1.png"))
		std::cout<<"Error loading texture 'map_2'"<<std::endl;
	if(!t_signal.loadFromFile("signal.png"))
		std::cout<<"Error loading texture 'signal'"<<std::endl;

	s_game_1.setTexture(t_game_1);
	s_game_1.setTextureRect(sf::IntRect(0, 0, 1366, 768));
	s_game_2.setTexture(t_game_2);
	s_game_2.setTextureRect(sf::IntRect(0, 0, 1366, 768));

	for (int i = 0; i < 3; i++)
	{
		s_signal[i].setTexture(t_signal);
		s_signal[i].setTextureRect(sf::IntRect(0, 0, 35, 34));
	}

	s_signal[0].setPosition(1131, 445);
	s_signal[1].setPosition(1131, 540);
	s_signal[2].setPosition(1131, 635);

	signal_time = sf::seconds(1);
}

Game_Location::~Game_Location()
{

}

std::string Game_Location::Get_Time()
{
	return std::to_string(round_time.getElapsedTime().asSeconds());
}

std::string Game_Location::Get_Gold_Poins()
{
	return result_drops = std::to_string(gold_drops_amount);
}

void Game_Location::Check_Event(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		hero_digit.Change_Hero_Digit(event);

		switch (event.key.code)
		{
		case sf::Keyboard::Escape: // принажатии клавиши 'Esc' переходим к локации выхода
			game_manager->Set_Active_Location(Space::EXITLOCATION);
			game_manager->previousLocation = &game_manager->game;
			break;

		case sf::Keyboard::Space:	// принажатии клавиши 'Space' проверяем совпали ли цифры
			if (isDigitsSame == true)
			{
				Compare_Digits();
			}		
			break;
		}
	}
}

int Game_Location::Compare_Digits()
{
	for (int i = 0; i < 3; i++)
	{
		if(hero_digit.Get_Digit() == digits[i])
		{
			if (DROP::BAD == drops.Check_Type(i)) // если имелась хотя бы одна красная капля в трубе
			{									  // вы проиграли					
				if (game_manager->isSoundOn == true)					
					game_manager->Play_Sound("fail");
				isDigitsSame = false;
				break;
			}
			if(DROP::GOLD == drops.Check_Type(i)) // если вам удалось "словить особую каплю"
			{									  // вы получаете 10 очков
				if (game_manager->isSoundOn == true)
					game_manager->Play_Sound("bonus");
				gold_drops_amount++;
				for (int i = 0; i < 10; i++)
				{
					score.Add_Point();
				}
				Set_Pile_Signal(i, sf::Color(0, 255, 34)); // труба вам об этом просигнализирует
			}
			if(DROP::NORMAL == drops.Check_Type(i)) // если же капля обычная
			{										// получаете 1 очко
				if (game_manager->isSoundOn == true)
					game_manager->Play_Sound("same");
				score.Add_Point();
				Set_Pile_Signal(i, sf::Color(0, 255, 34)); // о чем вам скажет сигнал на трубе
			}
			isDigitsSame = true;
			digits.Change_Container_Digit(i); // если числа совпали и тип капли был не красный
			return i;						  // число мгновенно поменяется
		}
		else isDigitsSame = false; // в противном случае флаг будет установлен в 'ложно' и ...
	}

	if(!isDigitsSame) // ... вы проиграли
	{
		if (game_manager->isSoundOn == true)
			game_manager->Play_Sound("fail"); 
		game_manager->result.Set_Score(score.Get_Score(), Get_Time(), Get_Gold_Poins());
		game_manager->Set_Active_Location(Space::RESULTLOCATION);
		game_manager->previousLocation = &game_manager->game;
		return -1;
	}	
}

void Game_Location::Run_Action()
{
	for (int i = 0; i < 3; i++)
	{
		if(DROP::BAD == drops.Check_Type(i)) // если в трубе текут красные капли, сигнал вам об этом подскажет
		{
			Set_Pile_Signal(i, sf::Color(212, 0, 0));
		}
		else
		{
			if (signal_clock[i].getElapsedTime() > signal_time)
				Set_Pile_Signal(i, sf::Color(154, 154, 154));
		}
	}

	if (hard_mode == true) // включение режима повышенной сложности установит большую скорость смены цифр в трубах
		digits.Change_Container_Digit(HARD_MODE_OFFSET, HARD_MODE_OFFSET, HARD_MODE_OFFSET);
	else
		digits.Change_Container_Digit(NORMAL_MODE_OFFSET, NORMAL_MODE_OFFSET, NORMAL_MODE_OFFSET);

	hero.Hero_Animation(); // запуск анимации героя
	drops.Run_Action();
}

void Game_Location::Set_Score(std::string start_score)
{
	score.Set_Score(start_score);
}

void Game_Location::Set_Game_Mode(bool toggle)
{
	hard_mode = toggle;
}

void Game_Location::Set_Pile_Signal(int pile_index, sf::Color color)
{	
	signal_clock[pile_index].restart();
	s_signal[pile_index].setColor(color);
}

void Game_Location::New_Game() // пересоздание игровой сессии
{
	hard_mode = false;
	isDigitsSame = true;
	gold_drops_amount = 0;
	result_drops = "000";  // при создании новой игры, сбрасываем счет в нули
	score.Set_Score("0000");

	s_signal[0].setPosition(1131, 445);
	s_signal[1].setPosition(1131, 540);
	s_signal[2].setPosition(1131, 635);

	signal_time = sf::seconds(1);
	round_time.restart();
}

void Game_Location::Draw() // отрисовка всех эл-ов игровой локации
{
	window.draw(s_game_2);
	drops.Draw_Oil_Drop_Container(window);
	window.draw(s_game_1);
	hero.Draw_Hero(window);
	digits.Draw_Oil_Digit_Container(window);
	score.Draw_Score(window);
	hero_digit.Draw_Hero_Digit(window);
	for (int i = 0; i < 3; i++)
		window.draw(s_signal[i]);
}
