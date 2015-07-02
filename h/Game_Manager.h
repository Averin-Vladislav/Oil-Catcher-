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
	friend class Exit_Location;   // класс оперирует большинством 
	friend class Game_Location;   // полей всех созданных классов
	friend class Start_Location;  // соответственно должен иметь
	friend class Result_Location; // прямой доступ к ним
	friend class Options_Location;
	friend class Sound;

	Exit_Location exit;
	Game_Location game;
	Start_Location start;
	Result_Location result;
	Options_Location options;
	Sound sound;

	sf::RenderWindow window; // создание окна игры
	Location* currentLocation; // два поля необходимые для отслеживания, 
	Location* previousLocation;// какое окно активно на данный момент и какое
							   // было активно до него
	std::map<Space, Location*> space_map; // карта соответствия типа области игры и классов локаций 

	bool isSoundOn; // включен ли звук

public:
	Game_Manager();
	~Game_Manager();

	void Run();
	void Set_Active_Location(Space new_space);
	void Play_Sound(std::string sound_name); // проигрывание коротких звуковых эффектов
	void Play_Music(std::string sound_name, bool isPause); // проигрывание длинных композиций
};


