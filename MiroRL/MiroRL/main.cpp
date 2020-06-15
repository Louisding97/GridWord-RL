
#include "Miro.h"
#include "Ai.h"
#include <iostream>
int main()
{
	Ai* ai = new Ai(true);


	for (int i = 0; i <10000; i++) 
	{
		ai->reward = 0;
		Miro* e1 = new Miro(ai);
		
		e1->render();
		ai->epsilon -= 0.0001;
		//std::cout << "bye" << std::endl;
	}

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
		std::cout << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;

	std::cout << ai->epsilon;
}
