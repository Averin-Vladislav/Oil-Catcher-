#include "Oil_Drop.h"
#include <vector>

class Oil_Drop_Container // хранит 3 вектора капель для каждой трубы
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

	int isRed_1; // может течь только 10 красных капель
	int isRed_2; // данные перемнные позволяют отлеживать
	int isRed_3; // отсавшееся кол-во капель для заполнения в вектор

	sf::Clock update; // данное поле требуется для установления скорости движения капли

public:

	Oil_Drop_Container();
	~Oil_Drop_Container();

	void Add_Drop();
	void Remove_Drop();
	void Run_Action();
	DROP Check_Type(int pile_index); // проверка типа капель, кот. текут на данный момент в трубе
	void Draw_Oil_Drop_Container(sf::RenderWindow &window);
};