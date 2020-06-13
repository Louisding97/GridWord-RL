#include "Ai.h"
#include "Tool.h"

#include <cstdlib>
#include <ctime>

Ai::Ai()
{

	std::srand(std::time(NULL));
	
	
}

int Ai::outWay()
{
	action = RIGHT;
	action = rand() % 4;		//·£´ýÁ¤Ã¥
	return action;
}

void Ai::CalCulationReward(double r, const int x, const int y)
{
	reward = r;
	
	XY* oldP = Positon::old(new XY(x, y), action);

	Method& m = state(oldP);

	double st = (r + MAX4(m.m_way[UP], m.m_way[DOWN], m.m_way[RIGHT], m.m_way[LEFT])) * 0.9;
	m.m_way[action] = st;


}

Method& Ai::state(XY* p)
{
	return m_state[p->y][p->x];
}
