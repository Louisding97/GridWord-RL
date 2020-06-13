
#include "Miro.h"
#include "Ai.h"
#include <iostream>
int main()
{
	Ai* ai = new Ai();


	for (int i = 0; i < 100000; i++) 
	{
		Miro* e1 = new Miro(ai);

		e1->render();
	}

	ai->m_state;
	for(int i = 0; i < Y_SIZE; i++)
	{
		for(int j = 0; j < X_SIZE; j++)
		{
			
			std::cout << ai->m_state[i][j].m_way[UP] << "	UP			";
			std::cout << ai->m_state[i][j].m_way[DOWN] << "	DOWN			";
			std::cout << ai->m_state[i][j].m_way[RIGHT] << "	RIGHT		";
			std::cout << ai->m_state[i][j].m_way[LEFT] << "	LEFT			";
				
			
			std::cout<< std::endl;
		}
	}
	

}
