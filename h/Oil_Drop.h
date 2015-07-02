#pragma once

#include < SFML/Graphics.hpp >

enum DROP {BAD, NORMAL, GOLD}; // ����� ������ ������� (������), ������� � ������ (��������, �������)

class Oil_Drop: public sf::Sprite
{
	DROP type;

public:

	Oil_Drop(sf::Texture& texture, sf::Vector2f start_position);
	~Oil_Drop();

	DROP Get_Type(); // �������� ��� ������� �����
	void Set_Type(DROP Type); // �������� ��� �����
};
