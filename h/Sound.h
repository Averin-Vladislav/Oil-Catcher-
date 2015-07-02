#pragma once

#include < SFML/Graphics.hpp >
#include < SFML\Audio.hpp >

class Sound
{
	sf::SoundBuffer sound_buffer_switch; // загрузка различных звуковых эффектов
	sf::SoundBuffer sound_buffer_enter;
	sf::SoundBuffer sound_buffer_select;
	sf::SoundBuffer sound_buffer_bonus;
	sf::SoundBuffer sound_buffer_same;
	sf::SoundBuffer sound_buffer_fail;

	sf::Sound sound_switch;
	sf::Sound sound_enter;
	sf::Sound sound_select;
	sf::Sound sound_bonus;
	sf::Sound sound_same;
	sf::Sound sound_fail;

	sf::Music music_menu; // загрузка фоновой музыки в меню

public:

	Sound();
	~Sound();

	void Switch(); // методы проигрывания звуков
	void Enter();
	void Select();
	void Bonus();
	void Same();
	void Fail();
	void Menu(bool isPause);
};
