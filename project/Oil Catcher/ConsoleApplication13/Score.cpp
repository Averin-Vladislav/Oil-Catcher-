#include "Score.h"
#include <iostream>

Score::Score()
{
	score_string="0000";
	result = 0;

	if(!t_score.loadFromFile("score.png"))
		std::cout<<"Error loading texture 'score'"<<std::endl;

	setTexture(t_score);
	setTextureRect(sf::IntRect(0, 0, 200, 266));
	setPosition(140, 420);

	score_font.loadFromFile("font.ttf");
	score_text.setFont(score_font);
	score_text.setColor(sf::Color::Black);
	score_text.setString(score_string);
	score_text.setCharacterSize(40);
	score_text.setPosition(190, 530);
}

Score::~Score()
{
	
}

void Score::Add_Point() // система добавления одного очка к строке счета
{
	if (score_string[3] == '9')
	{
		if(score_string[2] == '9')
		{
			if(score_string[1] == '9')
			{
				score_string[1] = '0';
				score_string[0]++;
				result++;
			}
			else 
				{
					score_string[1]++;
					result++;
				}
			score_string[2] = '0';
		}
		else 
		{
			score_string[2]++;
			result++;
		}
		score_string[3] = '0';
	}
	else 
	{
		score_string[3]++;
		result++;
	}

	score_text.setString(score_string); // возвращаем полученный счет
} 

std::string Score::Get_Score()
{
	return score_string;
}

void Score::Set_Score(std::string start_value)
{
	score_string = start_value;
	score_text.setString(score_string);
}

void Score::Draw_Score(sf::RenderWindow &window)
{
	window.draw(*this);
	window.draw(score_text);
}



