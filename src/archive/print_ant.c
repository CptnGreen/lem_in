#include "lem-in.h"

void	print_ant(t_ant *ant)
{
	if (ant)
	{
		printf("%3d| %-17s < %17s | %-2d | %-2d | %2d ", \
			   ant->num, ant->name, ((ant->parent) ? (ant->parent->name) : ("")), \
			   ant->x, ant->y, ant->depth);
		if (ant->is_start)
			printf("| start |");
		if (ant->is_end)
			printf("|  end  |");
		if (ant->is_chosen)
			printf("|   *   |");
		printf("\n");
	}
}
