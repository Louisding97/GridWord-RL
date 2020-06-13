#include "Ai.h"
#include "Tool.h"

#include <cstdlib>
#include <ctime>
#include <conio.h>
#include<iostream>

Ai::Ai()
{
	count = 0;
	
	
}

int Ai::outWay()
{

	std::srand(std::time(NULL));
	action = rand() % 4;		//랜덤정책
	reward -= 0.1;
	
	//if (count % 2 == 0)
	//{
	//	action = UP;
	//}
	//if (count % 2 == 1)
	//{
	//	action = RIGHT;
	//}
	//count++;
	int pressed_key; // 무슨 키가 눌렸는지

		// 만약 키가 눌렸다면 
		pressed_key = _getch(); //무슨 키인지 입력
		if (pressed_key == 72 || pressed_key == 119)
		{
			// ↑(W)

			action = UP;
		}
		if (pressed_key == 75 || pressed_key == 97)
		{
			// ←(A)

			action = LEFT;
		}

		if (pressed_key == 80 || pressed_key == 115)
		{
			// ↓(S)

			action = DOWN;
		}

		if (pressed_key == 77 || pressed_key == 100)
		{
			// →(D)
			action = RIGHT;
		}

		std::cout << action << std::endl;
	
	return action;
}

void Ai::CalCulationReward(double r, const int x, const int y)
{
	reward += r;
	
	XY* oldP = Positon::old(new XY(x, y), action);

	Method cu = m_state[y][x];

	double st = (reward + MAX4(cu.m_way[UP], cu.m_way[DOWN], cu.m_way[RIGHT], cu.m_way[LEFT]));

	Method& m = state(oldP);
	m.m_way[action] = st;


}

Method& Ai::state(XY* p)
{
	return m_state[p->y][p->x];
}
