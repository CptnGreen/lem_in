#include "lem-in.h"

void	print_room(t_room *room)
{
	t_ant_queue		*q;
	int				i;

	if (room)
	{
		printf("%3d| %-17s < %17s | %-2d | %-2d | %2d ", \
			   room->num, room->name, ((room->parent) ? (room->parent->name) : ("")), \
			   room->x, room->y, room->depth);
		if (room->is_start)
			printf("| start | ");
		if (room->is_end)
			printf("|  end  | ");
		if (room->is_chosen)
			printf("|   *   | ");
		q = room->ants;
		i = 0;
		while (q)
		{
			printf("L%d ", q->ant->num);
			i += 1;
			if (i > 10)
			{
				printf("...");
				break ;
			}
			q = q->next;
		}
		printf("\n");
	}
}
