#include <iostream>

#include "MiroRL.h"

int main()
{

	Environment* e1 = new Environment();
	AI* ai1 = new AI();


	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			std::cout << e1->map[i][j] << std::endl;
		}
	}
}
