
#include "api.hh"

int main()
{
	partie_init();
	for (int i = 0; i < NB_TOURS; ++i)
	{
		jouer_tour();
	}
	partie_fin();
}