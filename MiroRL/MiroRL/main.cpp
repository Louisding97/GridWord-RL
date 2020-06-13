
#include "Miro.h"
#include "Ai.h"
int main()
{
	Ai* ai = new Ai();


	for (int i = 0; i < 200; i++) 
	{
		Miro* e1 = new Miro(ai);

		e1->render();
	}

	ai->m_state;
	

}
