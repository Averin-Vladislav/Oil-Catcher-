#include "Location.h"
#include <iostream>

Location::Location(sf::RenderWindow& _window, Game_Manager* _game_manager) : window(_window), game_manager(_game_manager)
{
	if(!t_location.loadFromFile("background.png"))
		std::cout<<"Error loading texture 'background'"<<std::endl;
	setTexture(t_location);
}

Location::~Location()
{

}

std::string Get_Time()
{
	return NULL;
}

void Location::Run_Action()
{

}

void Location::Draw()
{
	window.draw(*this);
}

