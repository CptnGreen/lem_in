#include "lem-in.h"

int		print_ants(t_ant *ants)
{
	t_ant		*ant;

	if (ants)
	{
		printf("==#|=====last=room====|=d=|=flags=|\n");
		ant = ants;
		while (ant)
		{
			print_ant(ant);
			ant = ant->next;
		}
		printf("===|==================|===|=======|\n");
		return (OK);
	}
	perror("lem-in: Couldn't print ants 'cause passed argument is NULL.\n");
	return (KO);
}
