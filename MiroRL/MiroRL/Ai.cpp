#include "Ai.h"
#include "Tool.h"

#include <cstdlib>
#include <ctime>
#include <conio.h>
#include<iostream>

Ai::Ai(bool randPolicy)
{
	this->epsilon = 1;
	count = 0;
	this->m_Rand_policy = randPolicy;
	std::srand(std::time(NULL));
}

int Ai::outWay(XY* p)
{
	double Frand = std::rand() / (double)RAND_MAX;
	if(Frand < epsilon)
	{
		action = std::rand() % 4;		//랜덤정책
		
		
	}
	else
	{
		Method cu = state(p);
		MAX4(cu.m_way[UP], cu.m_way[DOWN], cu.m_way[RIGHT], cu.m_way[LEFT]);

		double max = cu.m_way[UP];

		int index = 0;
		for (int i = 1; i < 4; i++)
		{
			if (max < cu.m_way[i])
			{
				max = cu.m_way[i];
				index = i + 1;
			}
		}
		action = index;
	}


			
	//if (count % 2 == 0)
	//{
	//	action = UP;
	//}
	//if (count % 2 == 1)
	//{
	//	action = RIGHT;
	//}
	//count++;
	

	//int pressed_key; // 무슨 키가 눌렸는지

	//	// 만약 키가 눌렸다면 
	//	pressed_key = _getch(); //무슨 키인지 입력
	//	if (pressed_key == 72 || pressed_key == 119)
	//	{
	//		// ↑(W)

	//		action = UP;
	//	}
	//	if (pressed_key == 75 || pressed_key == 97)
	//	{
	//		// ←(A)

	//		action = LEFT;
	//	}

	//	if (pressed_key == 80 || pressed_key == 115)
	//	{
	//		// ↓(S)

	//		action = DOWN;
	//	}

	//	if (pressed_key == 77 || pressed_key == 100)
	//	{
	//		// →(D)
	//		action = RIGHT;
	//	}

	//	std::cout << action << std::endl;
	
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


void Ai::setRandomPolicy(bool rp)
{
	m_Rand_policy = rp;
}
