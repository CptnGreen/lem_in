#include "lem-in.h"

int		print_rooms(t_room *rooms)
{
	t_room		*room;
	int			i;

	printf("Printing sequence of rooms:\n");
	printf("==========================\n");
	if (rooms)
	{
		i = 0;
		room = rooms;
		while (room)
		{
			printf("%3d: \"%s\" (%2d, %2d)\n", i, room->name, room->x, room->y);
			room = room->next;
			i += 1;
		}
		printf("==========================\n");
		return (OK);
	}
	perror("lem-in: Couldn't print rooms 'cause passed argument is NULL.\n");
	printf("==========================\n");
	return (KO);
}
