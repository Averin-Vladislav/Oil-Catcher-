#include "Oil_Drop_Container.h"
#include <iostream>

#define SPEED -200.0 // �������� ������  ������
#define OFFSET sf::milliseconds(350) // �������� �� ��������
#define AMOUNT_OF_RED_DROPS 9 // ���-�� ������� ������ (����� ���� �� �����)

Oil_Drop_Container::Oil_Drop_Container()
{
	if(!t_oil_drop.loadFromFile("drop.png"))
		std::cout<<"Error loading texture 'drop'"<<std::endl;

	start_pos_1 = sf::Vector2f(1100, 450);
	start_pos_2 = sf::Vector2f(1100, 547);
	start_pos_3 = sf::Vector2f(1100, 640);

	isRed_1 = 0;
	isRed_2 = 0;
	isRed_3 = 0;

	remove_position_1 = 400.0; // �������, �� ���������� �������
	remove_position_2 = 400.0; // ����� ����� ��������� ��
	remove_position_3 = 500.0; // ��������

	clock_1.restart();
	clock_2.restart();
	clock_3.restart();
}

Oil_Drop_Container::~Oil_Drop_Container()
{
	for(int i = 0; i < Oil_Drop_Vector_1.size(); i++)
		delete Oil_Drop_Vector_1[i];

	for(int i = 0; i < Oil_Drop_Vector_2.size(); i++)
		delete Oil_Drop_Vector_2[i];

	for(int i = 0; i < Oil_Drop_Vector_3.size(); i++)
		delete Oil_Drop_Vector_3[i];
}

void Oil_Drop_Container::Add_Drop()
{
	if(clock_1.getElapsedTime() > OFFSET) // ���� ���������� ����� ������� ��������� �������� �������� 
	{
		clock_1.restart(); // ��������� ��� ������
		if(isRed_1) // ��������� - �� ������ �� �������� ������� ����� (����� �� 10)
		{
			Oil_Drop_Vector_1.push_back(new Oil_Drop(t_oil_drop, start_pos_1));
			Oil_Drop_Vector_1[Oil_Drop_Vector_1.size()-1]->Set_Type(DROP::BAD);
			isRed_1--; // ���� �������� �� ��������� �� ���-��
		}
		else // ���� �� ������ �������� ������� �����...
		{
			if(!(rand()%100)) // ���������� ���� ��������� ������� �����
			{
				Oil_Drop_Vector_1.push_back(new Oil_Drop(t_oil_drop, start_pos_1));
				Oil_Drop_Vector_1[Oil_Drop_Vector_1.size()-1]->Set_Type(DROP::GOLD);
			}
			else // ���� �� ������ ���� ������� �����...
			{
				if(!(rand()%50)) // ���������� ���� ��������� ������� �����
				{
					Oil_Drop_Vector_1.push_back(new Oil_Drop(t_oil_drop, start_pos_1));
					Oil_Drop_Vector_1[Oil_Drop_Vector_1.size()-1]->Set_Type(DROP::BAD);
					isRed_1 = AMOUNT_OF_RED_DROPS; // ������ ���-�� ������� ������, ������� ������ ���� ����������
				}
				else // � ������ ������������� �������� �� ���� ��������� �������, ��������� ������� �����
				{
					Oil_Drop_Vector_1.push_back(new Oil_Drop(t_oil_drop, start_pos_1));
					Oil_Drop_Vector_1[Oil_Drop_Vector_1.size()-1]->Set_Type(DROP::NORMAL);
				}
			}
		}
	}
	// ������ �������� ��������� ��� ������ �����
	if(clock_2.getElapsedTime() > OFFSET)
	{
		clock_2.restart();
		if(isRed_2)
		{
			Oil_Drop_Vector_2.push_back(new Oil_Drop(t_oil_drop, start_pos_2));
			Oil_Drop_Vector_2[Oil_Drop_Vector_2.size()-1]->Set_Type(DROP::BAD);
			isRed_2--;
		}
		else
		{
			if(!(rand()%100))
			{
				Oil_Drop_Vector_2.push_back(new Oil_Drop(t_oil_drop, start_pos_2));
				Oil_Drop_Vector_2[Oil_Drop_Vector_2.size()-1]->Set_Type(DROP::GOLD);
			}
			else
			{
				if(!(rand()%50))
				{
					
					Oil_Drop_Vector_2.push_back(new Oil_Drop(t_oil_drop, start_pos_2));
					Oil_Drop_Vector_2[Oil_Drop_Vector_2.size()-1]->Set_Type(DROP::BAD);
					isRed_2 = AMOUNT_OF_RED_DROPS;
				}
				else
				{
					Oil_Drop_Vector_2.push_back(new Oil_Drop(t_oil_drop, start_pos_2));
					Oil_Drop_Vector_2[Oil_Drop_Vector_2.size()-1]->Set_Type(DROP::NORMAL);
				}
			}
		}
	}

	if(clock_3.getElapsedTime() > OFFSET)
	{
		clock_3.restart();
		if(isRed_3)
		{
			Oil_Drop_Vector_3.push_back(new Oil_Drop(t_oil_drop, start_pos_3));
			Oil_Drop_Vector_3[Oil_Drop_Vector_3.size()-1]->Set_Type(DROP::BAD);
			isRed_3--;
		}
		else
		{
			if(!(rand()%100))
			{
				Oil_Drop_Vector_3.push_back(new Oil_Drop(t_oil_drop, start_pos_3));
				Oil_Drop_Vector_3[Oil_Drop_Vector_3.size()-1]->Set_Type(DROP::GOLD);
			}
			else
			{
				if(!(rand()%50))
				{
					Oil_Drop_Vector_3.push_back(new Oil_Drop(t_oil_drop, start_pos_3));
					Oil_Drop_Vector_3[Oil_Drop_Vector_3.size()-1]->Set_Type(DROP::BAD);
					isRed_3 = AMOUNT_OF_RED_DROPS;
				}
				else
				{
					Oil_Drop_Vector_3.push_back(new Oil_Drop(t_oil_drop, start_pos_3));
					Oil_Drop_Vector_3[Oil_Drop_Vector_3.size()-1]->Set_Type(DROP::NORMAL);
				}
			}
		}
	}
}

void Oil_Drop_Container::Remove_Drop()
{
	if(Oil_Drop_Vector_1.size())
	if((Oil_Drop_Vector_1[0])->getPosition().x < remove_position_1) // �� ���������� �������� �������
	{																// �������� ������, ������� ��
		delete Oil_Drop_Vector_1[0];								// �� �����. ��������
		Oil_Drop_Vector_1.erase(Oil_Drop_Vector_1.begin());
	}
	if(Oil_Drop_Vector_2.size())
	if((Oil_Drop_Vector_2[0])->getPosition().x < remove_position_2)
	{
		delete Oil_Drop_Vector_2[0];
		Oil_Drop_Vector_2.erase(Oil_Drop_Vector_2.begin());
	}
	if(Oil_Drop_Vector_3.size())
	if((Oil_Drop_Vector_3[0])->getPosition().x < remove_position_3)
	{
		delete Oil_Drop_Vector_3[0];
		Oil_Drop_Vector_3.erase(Oil_Drop_Vector_3.begin());
	}
}

void Oil_Drop_Container::Run_Action()
{
	Add_Drop();

	for(int i = 0; i < Oil_Drop_Vector_1.size(); i++) // ������������ ���� ������ � �������
	{												  // � �������� ���������
		Oil_Drop_Vector_1[i]->move(sf::Vector2f(SPEED*update.getElapsedTime().asSeconds(),0));
	}

	for(int i = 0; i < Oil_Drop_Vector_2.size(); i++)
	{
		Oil_Drop_Vector_2[i]->move(sf::Vector2f(SPEED*update.getElapsedTime().asSeconds(),0));
	}

	for(int i = 0; i < Oil_Drop_Vector_3.size(); i++)
	{
		Oil_Drop_Vector_3[i]->move(sf::Vector2f(SPEED*update.getElapsedTime().asSeconds(),0));
	}

	update.restart();

	Remove_Drop();
}

DROP Oil_Drop_Container::Check_Type(int pile_index)
{
	switch (pile_index) 
	{
	case 0:
		for(int i = 0; i < Oil_Drop_Vector_1.size(); i++)
		{
			if(Oil_Drop_Vector_1[i]->Get_Type() == DROP::BAD)
				return DROP::BAD;
		}
		for(int i = 0; i < Oil_Drop_Vector_1.size(); i++)
		{
			if(Oil_Drop_Vector_1[i]->Get_Type() == DROP::GOLD)
				return DROP::GOLD;
		}
		return DROP::NORMAL;
		break;

	case 1:
		for(int i = 0; i < Oil_Drop_Vector_2.size(); i++)
		{
			if(Oil_Drop_Vector_2[i]->Get_Type() == DROP::BAD)
				return DROP::BAD;
		}
		for(int i = 0; i < Oil_Drop_Vector_2.size(); i++)
		{
			if(Oil_Drop_Vector_2[i]->Get_Type() == DROP::GOLD)
				return DROP::GOLD;
		}
		return DROP::NORMAL;
		break;

	case 2:
		for(int i = 0; i < Oil_Drop_Vector_3.size(); i++)
		{
			if(Oil_Drop_Vector_3[i]->Get_Type() == DROP::BAD)
				return DROP::BAD;
		}
		for(int i = 0; i < Oil_Drop_Vector_3.size(); i++)
		{
			if(Oil_Drop_Vector_3[i]->Get_Type() == DROP::GOLD)
				return DROP::GOLD;
		}
		return DROP::NORMAL;
		break;
	}
}

void Oil_Drop_Container::Draw_Oil_Drop_Container(sf::RenderWindow &window)
{
	for(int i = 0; i < Oil_Drop_Vector_1.size(); i++)
	{
		window.draw(*(Oil_Drop_Vector_1[i]));
	}

	for(int i = 0; i < Oil_Drop_Vector_2.size(); i++)
	{
		window.draw(*(Oil_Drop_Vector_2[i]));
	}

	for(int i = 0; i < Oil_Drop_Vector_3.size(); i++)
	{
		window.draw(*(Oil_Drop_Vector_3[i]));
	}
}

