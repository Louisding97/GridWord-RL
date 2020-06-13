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
	
	Ai();

	int outWay();

	void reward(int r);

	Method state(const int x, const int y);
};