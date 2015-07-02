#include "Oil_Drop.h"
#include <vector>

class Oil_Drop_Container // ������ 3 ������� ������ ��� ������ �����
{
	sf::Texture t_oil_drop;
	
	std::vector<Oil_Drop*> Oil_Drop_Vector_1;
	std::vector<Oil_Drop*> Oil_Drop_Vector_2;
	std::vector<Oil_Drop*> Oil_Drop_Vector_3;

	sf::Clock clock_1;
	sf::Clock clock_2;
	sf::Clock clock_3;

	sf::Vector2f start_pos_1;
	sf::Vector2f start_pos_2;
	sf::Vector2f start_pos_3;

	float remove_position_1;
	float remove_position_2;
	float remove_position_3;

	int isRed_1; // ����� ���� ������ 10 ������� ������
	int isRed_2; // ������ ��������� ��������� ����������
	int isRed_3; // ���������� ���-�� ������ ��� ���������� � ������

	sf::Clock update; // ������ ���� ��������� ��� ������������ �������� �������� �����

public:

	Oil_Drop_Container();
	~Oil_Drop_Container();

	void Add_Drop();
	void Remove_Drop();
	void Run_Action();
	DROP Check_Type(int pile_index); // �������� ���� ������, ���. ����� �� ������ ������ � �����
	void Draw_Oil_Drop_Container(sf::RenderWindow &window);
};