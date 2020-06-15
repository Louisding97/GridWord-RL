#include "Miro.h"


#include <iostream>



#include <windows.h>


Miro::Miro(Ai *agent)
{
	this->agent = agent;
	for (int y = 0; y < Y_SIZE; y++)
	{
		for (int x = 0; x < X_SIZE; x++)
		{
			map[y][x] = 0;
		}
	}

	map[Y_SIZE - 1][X_SIZE - 1] = -2;
	map[Y_SIZE - 1][X_SIZE - 2] = 3;

}

bool Miro::verificationOfLocation()
{
	if (m_player_y < Y_SIZE && m_player_y >= 0)
	{
		if (m_player_x < X_SIZE && m_player_x >= 0)
		{
			return true;
		}
	}
	return false;
}

int Miro::move(const int way)
{
	int old_x = m_player_x;
	int old_y = m_player_y;
	try
	{
		if (way == UP)
		{
			m_player_y++;
		}
		else if (way == DOWN)
		{
			m_player_y--;
		}
		else if (way == RIGHT)
		{
			m_player_x++;
		}
		else if (way == LEFT)
		{
			m_player_x--;
		}

		if (!verificationOfLocation())
		{
			m_player_x = old_x;
			m_player_y = old_y;
			throw -1;
		}
		// reward 가 있다면
		if(map[m_player_y][m_player_x] != 0)
		{
			return map[m_player_y][m_player_x];
		}
	}
	catch (int e)
	{
		return e;
	}
	return 0;
}



int Miro::render()
{
	while (1)
	{
		int res;
		do
		{
			res = move(agent->outWay(new XY(m_player_x, m_player_x)));
		} while (res == -1);
		agent->reward -= 0.1;		//한턴에 리워드 -0.1
		
		agent->CalCulationReward(getReward(), m_player_x, m_player_y);

		
		if (res != 0)	//out of map or get reward
		{
			return 0;
		}
	}
}


int Miro::getReward()
{
	if(!verificationOfLocation())
	{
		return -1;
	}
	return map[m_player_y][m_player_x];
}
