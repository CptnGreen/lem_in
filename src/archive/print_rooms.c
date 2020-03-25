#include "lem-in.h"

int		print_rooms(t_room *rooms)
{
	t_room		*room;

	if (rooms)
	{
		room = rooms;
		while (room)
		{
			if (!(room->is_start || room->is_end))
				printf("%s %d %d\n", room->name, room->x, room->y);
			room = room->next;
		}
		return (OK);
	}
	perror("lem-in: Couldn't print rooms 'cause passed argument is NULL.\n");
	return (KO);
}
