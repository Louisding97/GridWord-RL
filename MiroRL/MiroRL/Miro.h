#pragma once

#include "Ai.h"
#include "Tool.h"

class Miro
{
public:

	int m_player_x = 0;
	int m_player_y = 0;

	Ai* agent1;


	int map[Y_SIZE][X_SIZE];  //map ���� reward �� �ִ�'

	Miro();

	bool verificationOfLocation();

	int move(const int way);


	int render();
	
	int getReward();
};


