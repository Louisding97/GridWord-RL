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
private:
	int m_player_x = 0;
	int m_player_y = 0;

public:
	int map[Y_SIZE][X_SIZE];
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
	void move(const int way)
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
				m_player_x--;
			}
			else if (way == LEFT)
			{
				m_player_x--;
			}

			if (verificationOfLocation())
			{
				throw - 1;
			}
		}
		catch (int e)
		{
			throw - 1;
		}

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