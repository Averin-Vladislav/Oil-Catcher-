#pragma once

#include < SFML/Graphics.hpp >
#include <iostream>
#include "Exit_Location.h"
#include "Game_Location.h"
#include "Result_Location.h"
#include "Start_Location.h"
#include "Options_Location.h"
#include "Sound.h"

class Location;
enum Space {EXITLOCATION, GAMELOCATION, STARTLOCATION, RESULTLOCATION, OPTIONSLOCATION}; 

class Game_Manager
{
	friend class Exit_Location;   // ����� ��������� ������������ 
	friend class Game_Location;   // ����� ���� ��������� �������
	friend class Start_Location;  // �������������� ������ �����
	friend class Result_Location; // ������ ������ � ���
	friend class Options_Location;
	friend class Sound;

	Exit_Location exit;
	Game_Location game;
	Start_Location start;
	Result_Location result;
	Options_Location options;
	Sound sound;

	sf::RenderWindow window; // �������� ���� ����
	Location* currentLocation; // ��� ���� ����������� ��� ������������, 
	Location* previousLocation;// ����� ���� ������� �� ������ ������ � �����
							   // ���� ������� �� ����
	std::map<Space, Location*> space_map; // ����� ������������ ���� ������� ���� � ������� ������� 

	bool isSoundOn; // ������� �� ����

public:
	Game_Manager();
	~Game_Manager();

	void Run();
	void Set_Active_Location(Space new_space);
	void Play_Sound(std::string sound_name); // ������������ �������� �������� ��������
	void Play_Music(std::string sound_name, bool isPause); // ������������ ������� ����������
};


