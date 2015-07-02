#pragma once

#include < SFML/Graphics.hpp >
#include "Oil_Digit.h"

class Oil_Digit_Container // контейнер хранит 3 цифры
{
	Oil_Digit oil_digit_1;
	Oil_Digit oil_digit_2;
	Oil_Digit oil_digit_3;

public:

	Oil_Digit_Container();
	~Oil_Digit_Container();

	void Change_Container_Digit(float frequency_1, float frequency_2, float frequency_3); // принимает частоту изменения цифр
	void Change_Container_Digit(int index); // принимает индекс трубы, в которой требуется заменитть цифру
	sf::Time Get_Time(int index);
	void Draw_Oil_Digit_Container(sf::RenderWindow& window);

	int operator [](int i)
	{
		if(i == 0)
			return oil_digit_1.Get_Digit();
		if(i == 1)
			return oil_digit_2.Get_Digit();
		if(i == 2)
			return oil_digit_3.Get_Digit();
	}
};
