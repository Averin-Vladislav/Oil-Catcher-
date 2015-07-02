#pragma once

#include < SFML/Graphics.hpp >
#include <iostream>
#include "Location.h"
#include "Hero.h"
#include "Score.h"
#include "Hero_Digit.h"
#include "Oil_Digit_Container.h"
#include "Oil_Drop_Container.h"

class Game_Manager;
class location;
enum Space;

class Game_Location: public Location
{
	Hero hero;
	Score score;
	Hero_Digit hero_digit;
	Oil_Digit_Container digits;
	Oil_Drop_Container drops;

	sf::Texture t_game_1; // 2 �������� �������� ����, �.�.
	sf::Texture t_game_2; // ����� ���������� ������������� 
	sf::Sprite s_game_1;  // ����� ������� ������ ����� 
	sf::Sprite s_game_2;

	sf::Texture t_signal; // ������ �����, ��������������� � ������� ������ ��������
	sf::Sprite s_signal[3];
	
	int gold_drops_amount; // ���� ��� �������� ���-�� ������ ������, � ����������� ������ � ������� ����������
	std::string result_drops;
	bool hard_mode; // ���������/���������� ������ ���������� ���������
	bool isDigitsSame; // ������� �� �����

	sf::Clock signal_clock[3]; // ���� ��� ����� �������
	sf::Time signal_time;

	sf::Clock round_time;

public:

	Game_Location(sf::RenderWindow& window, Game_Manager* game_manager);
	~Game_Location();

	std::string Get_Time();
	std::string Get_Gold_Poins();
	void Check_Event(const sf::Event& event);
	int Compare_Digits();
	void Set_Score(std::string start_score);
	void Set_Game_Mode(bool toggle);
	void Run_Action();
	void Set_Pile_Signal(int pile_index, sf::Color color);
	void New_Game();
	void Draw();
};
