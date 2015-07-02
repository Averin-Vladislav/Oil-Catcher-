#include "Oil_Digit_Container.h"

Oil_Digit_Container::Oil_Digit_Container()
{
	oil_digit_1.Set_Oil_Digit_Position(1025, 410);
	oil_digit_2.Set_Oil_Digit_Position(1025, 507);
	oil_digit_3.Set_Oil_Digit_Position(1025, 600);
}

Oil_Digit_Container::~Oil_Digit_Container()
{

}

void Oil_Digit_Container::Change_Container_Digit(float frequency_1, float frequency_2, float frequency_3)
{		
	oil_digit_1.Change_Oil_Digit(sf::seconds(frequency_1));
	oil_digit_2.Change_Oil_Digit(sf::seconds(frequency_2));
	oil_digit_3.Change_Oil_Digit(sf::seconds(frequency_3));
}

void Oil_Digit_Container::Change_Container_Digit(int index)
{		
	switch(index)
	{
	case 0:
		oil_digit_1.Change_Oil_Digit(sf::seconds(0.3));
		break;

	case 1:
		oil_digit_2.Change_Oil_Digit(sf::seconds(0.3));
		break;

	case 2:
		oil_digit_3.Change_Oil_Digit(sf::seconds(0.3));
		break;
	}
}

sf::Time Oil_Digit_Container::Get_Time(int index)
{
	switch (index)
	{
	case 0:
		return oil_digit_1.Get_Time();
		break;

	case 1:
		return oil_digit_2.Get_Time();
		break;

	case 2:
		return oil_digit_3.Get_Time();
		break;
	}
}

void Oil_Digit_Container::Draw_Oil_Digit_Container(sf::RenderWindow& window)
{
	oil_digit_1.Draw_Oil_Digit(window);
	oil_digit_2.Draw_Oil_Digit(window);
	oil_digit_3.Draw_Oil_Digit(window);
}

