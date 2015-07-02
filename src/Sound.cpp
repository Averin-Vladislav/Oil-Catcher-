#include "Sound.h"

Sound::Sound()
{
	sound_buffer_switch.loadFromFile("switch.wav");
	sound_switch.setBuffer(sound_buffer_switch);

	sound_buffer_enter.loadFromFile("enter.ogg");
	sound_enter.setBuffer(sound_buffer_enter);

	sound_buffer_select.loadFromFile("select.wav");
	sound_select.setBuffer(sound_buffer_select);

	sound_buffer_bonus.loadFromFile("bonus.wav");
	sound_bonus.setBuffer(sound_buffer_bonus);

	sound_buffer_same.loadFromFile("same.wav");
	sound_same.setBuffer(sound_buffer_same);

	sound_buffer_fail.loadFromFile("fail.wav");
	sound_fail.setBuffer(sound_buffer_fail);

	music_menu.openFromFile("menu.wav");
}

Sound::~Sound()
{

}

void Sound::Switch()
{
	sound_switch.play();
}

void Sound::Enter()
{
	sound_enter.play();
}

void Sound::Select()
{
	sound_select.play();
}

void Sound::Bonus()
{
	sound_bonus.play();
}

void Sound::Same()
{
	sound_same.play();
}

void Sound::Fail()
{
	sound_fail.play();
}

void Sound::Menu(bool isPause) // в зависимости от того какая локация активна, фоновая
{							   // музыка меню будет ставиться на паузу или проигрываться
	if (isPause == true)
		music_menu.pause();
	else
	{
		music_menu.play();
		music_menu.setLoop(true); // ставим отрывок на повтор
	}
}





