#include "Miro.h"

Miro::Miro()
{
	for (int y = 0; y < Y_SIZE; y++)
	{
		for (int x = 0; x < X_SIZE; x++)
		{
			map[y][x] = 0;
		}
	}

	map[Y_SIZE - 1][X_SIZE - 1] = 3;
	map[Y_SIZE - 1][X_SIZE - 2] = -2;

	agent1 = new Ai();
}

bool Miro::verificationOfLocation()
{
	if (m_player_y < Y_SIZE && m_player_y >= 0)
	{
		if (m_player_x < Y_SIZE && m_player_x >= 0)
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

		if (verificationOfLocation())
		{
			throw -1;
		}
	}
	catch (int e)
	{
		return -1;
	}
}

void Miro::input(const int way)
{
	int code = move(way);
}

int Miro::render()
{
	input();
}


int Miro::getReward()
{
	return map[m_player_y][m_player_x];
}
