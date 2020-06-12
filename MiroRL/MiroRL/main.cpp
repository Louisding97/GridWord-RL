#include <iostream>

#include "Miro.h"

int main()
{
	Miro* e1 = new Miro();
	AI* ai1 = new AI();

	

	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			std::cout << e1->map[i][j] << std::endl;
		}
	}

}
