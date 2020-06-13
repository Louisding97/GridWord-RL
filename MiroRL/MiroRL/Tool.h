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

class XY
{
public:
	XY(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int x;
	int y;
};

class Positon
{
public:
	Positon()
	{
		
	}
	static XY* old(XY* current, int action)
	{
		if (action == UP)
		{
			current->y--;
		}
		else if (action == DOWN)
		{
			current->y++;
		}
		else if (action == RIGHT)
		{
			current->x--;
		}
		else if (action == LEFT)
		{
			current->x++;
		}
		return current;
	}
};

