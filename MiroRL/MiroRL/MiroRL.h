#pragma once
#define X_SIZE 3
#define Y_SIZE 2

enum Way
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};


class Environment
{
public:

	int m_player_x = 0;
	int m_player_y = 0;


	int map[Y_SIZE][X_SIZE];  //map 에는 reward 가 있다'
	
	Environment()
	{
		for (int y = 0; y < Y_SIZE; y++)
		{
			for (int x = 0; x < X_SIZE; x++)
			{
				map[y][x] = 0;
			}
		}
		
		map[Y_SIZE-1][X_SIZE-1] = 3;
		map[Y_SIZE - 1][X_SIZE - 2] = -2;
		
	}
	bool verificationOfLocation()
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
	
	int move(const int way)
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
	void input(const int way)
	{
		int code = move(way);
	}

	int getReward()
	{
		return map[m_player_y][m_player_x];
	}
};


class Method
{
public:
	double m_way[4];
};

class AI
{
public:
	Method m_state[Y_SIZE][X_SIZE];

	Method state(const int x, const int y)
	{
		return m_state[y][x];
	}
};