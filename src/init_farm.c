#include "lem-in.h"

int		init_farm(t_farm *farm)
{
	if (farm)
	{
		farm->ants = NULL;
		farm->rooms = NULL;
		farm->links = NULL;
		farm->n_ants = 0;
		farm->n_rooms = 0;
		farm->start_counter = 0;
		farm->end_counter = 0;
		farm->adj_matrix = NULL;
		printf("Ant farm successfully initialized!\n");
		return (OK);
	}
	return (KO);
}
