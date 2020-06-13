#pragma once

#include "Tool.h"

class Method
{
public:
	double m_way[4];
};


class Ai
{
public:
	Method m_state[Y_SIZE][X_SIZE];
	double reward;
	int action;

	
	Ai();

	int outWay();

	void CalCulationReward(double r, const int x, const int y);

	Method state(const int x, const int y);
};