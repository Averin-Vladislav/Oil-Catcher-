#pragma once

#include < SFML/Graphics.hpp >

class Game_Manager;

class Location: public sf::Sprite
{
protected:

	sf::Texture t_location;
	sf::RenderWindow& window; // ссылка на окно игры
	Game_Manager* game_manager; // ук-ль на класс управления игрой

public:

	Location(sf::RenderWindow& _window, Game_Manager* game_manager);
	~Location();

	std::string Get_Time();
	virtual void Run_Action();
	virtual void Check_Event(const sf::Event& event) = 0;
	virtual void Draw();
};