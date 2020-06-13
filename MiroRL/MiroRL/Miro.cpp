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

	agent = new Ai();
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
		/*for (int i = Y_SIZE-1; i >= 0; i--)
		{
			for (int j = 0; j < 3; j++)
			{
					std::cout << map[i][j] ;
			}
			std::cout << std::endl;
		}*/
		
		int res = move(agent->outWay());
		
		agent->CalCulationReward(getReward(), m_player_x, m_player_y);
		
		if (res != 0)	//out of map or get reward
		{
			return 0;
		}
		

		/*
		Sleep(3000); 
		system("cls");*/
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
