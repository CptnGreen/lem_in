#include "lem-in.h"

void	init_farm(t_farm *farm)
{
	if (farm)
	{
		farm->ants = NULL;
		farm->rooms = NULL;
		farm->n_ants = 0;
		farm->n_rooms = 0;
	}
}
