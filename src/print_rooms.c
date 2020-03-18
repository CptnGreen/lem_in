#include "lem-in.h"

int		print_rooms(t_room *rooms)
{
	t_room		*room;

	printf("==#==name==============x====y====d==\n");
	if (rooms)
	{
		room = rooms;
		while (room)
		{
			printf("%3d| %-15s | %-2d | %-2d | %-2d ", \
				   room->num, room->name, room->x, room->y, room->depth);
			if (room->is_start)
				printf("- start -");
			if (room->is_end)
				printf("-  end  -");
			printf("\n");
			room = room->next;
		}
		printf("====================================\n");
		return (OK);
	}
	perror("lem-in: Couldn't print rooms 'cause passed argument is NULL.\n");
	printf("====================================\n");
	return (KO);
}
