#include "Ai.h"
#include "Tool.h"

#include <cstdlib>
#include <ctime>

Ai::Ai()
{

	
	
}

int Ai::outWay()
{

	std::srand(std::time(NULL));
	action = rand() % 4;		//·£´ýÁ¤Ã¥


	return action;
}

void Ai::CalCulationReward(double r, const int x, const int y)
{
	reward = r;
	
	XY* oldP = Positon::old(new XY(x, y), action);

	Method cu = m_state[y][x];

	double st = (r + MAX4(cu.m_way[UP], cu.m_way[DOWN], cu.m_way[RIGHT], cu.m_way[LEFT]));

	Method& m = state(oldP);
	m.m_way[action] = st;


}

Method& Ai::state(XY* p)
{
	return m_state[p->y][p->x];
}
