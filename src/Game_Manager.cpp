#include "Game_Manager.h"
#include "Game_Location.h"
#include "Exit_Location.h"
#include <map>

Game_Manager::Game_Manager() : window(sf::VideoMode(1366, 768), "Oil Catcher", sf::Style::Fullscreen)
	, result(window, this)
	, exit(window, this)
	, start(window, this)
	, game(window, this)
	, options(window, this)
{
	Digit::Load_Texture();

	window.setMouseCursorVisible(0); // отключение видимости курсора в игре

	space_map.insert(std::make_pair(Space::GAMELOCATION, &game));
	space_map.insert(std::make_pair(Space::EXITLOCATION, &exit));
	space_map.insert(std::make_pair(Space::RESULTLOCATION, &result));
	space_map.insert(std::make_pair(Space::STARTLOCATION, &start));
	space_map.insert(std::make_pair(Space::OPTIONSLOCATION, &options));

	currentLocation = &start;
	previousLocation = &start;

	isSoundOn = true; // звук по умолчанию включен
}

Game_Manager::~Game_Manager()
{

}

void Game_Manager::Run()
{
	sound.Menu(false); // проигрывает музыкальную композицию фоновой музыки в меню

	while (window.isOpen())
	{
		sf::Event event; // переменная для хранения типа события

		while (window.pollEvent(event))
		{
			currentLocation->Check_Event(event); // проверяем событие текущего окна

			switch (event.type)
			{
				case sf::Event::Closed: // если нажат красный крестик - игра закрывается
					window.close();
					break;
			}			
		}

		currentLocation->Run_Action(); // запуск каких либо событий текущего окна
									   // независимых от внешний событий
		window.clear(); // очистка окна

		if (currentLocation == &exit) // локация выхода рисуется поверх предыдущего окна
		{
			previousLocation->Draw();
			currentLocation->Draw();
		}
		else
		currentLocation->Draw();
		
		window.display(); // прорисовка окна
	}
}

void Game_Manager::Set_Active_Location(Space new_space)
{
	currentLocation = space_map[new_space];
}

void Game_Manager::Play_Sound(std::string sound_name)
{
	if (sound_name == "enter")
		sound.Enter();
	if (sound_name == "select")
		sound.Select();
	if (sound_name == "switch")
		sound.Switch();	
	if (sound_name == "bonus")
		sound.Bonus();
	if (sound_name == "same")
		sound.Same();
	if (sound_name == "fail")
		sound.Fail();
}

void Game_Manager::Play_Music(std::string sound_name, bool isPause)
{
	if (sound_name == "menu")
		sound.Menu(isPause);
}



