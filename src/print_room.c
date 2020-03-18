#include "lem-in.h"

void	print_room(t_room *room)
{
	if (room)
	{
		printf("%3d| %-15s | %-2d | %-2d | %2d ", \
			   room->num, room->name, room->x, room->y, room->depth);
		if (room->is_start)
			printf("- start -");
		if (room->is_end)
			printf("-  end  -");
		printf("\n");
	}
}
