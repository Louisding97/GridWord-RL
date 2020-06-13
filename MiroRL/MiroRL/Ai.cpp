#include "Ai.h"
#include "Tool.h"

#include <cstdlib>
#include <ctime>

Ai::Ai()
{
	std::srand(static_cast<unsigned int>(std::time(0)));

}

int Ai::outWay()
{
	int action = rand() % 4;
	return action;
}

void Ai::CalCulationReward(double r, const int x, const int y)
{
	reward = r;
	
	XY* oldP = Positon::old(new XY(x, y), action);
	
	state(x, y);
}

Method Ai::state(const int x, const int y)
{
	return m_state[y][x];
}
