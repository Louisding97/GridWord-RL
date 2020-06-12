#pragma once
#define X_SIZE 3
#define Y_SIZE 2

#include "Ai.h"
enum Way
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};


class Miro
{
public:

	int m_player_x = 0;
	int m_player_y = 0;

	Ai* agent1;


	int map[Y_SIZE][X_SIZE];  //map 에는 reward 가 있다'

	Miro();

	bool verificationOfLocation();

	int move(const int way);

	void input(const int way);

	int render();
	
	int getReward();
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