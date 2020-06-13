
#include "Miro.h"
#include "Ai.h"
int main()
{
	Ai* ai = new Ai();

	
	Miro* e1 = new Miro(ai);

	e1->render();
	

}
