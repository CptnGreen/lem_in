#include "lem-in.h"

int		print_rooms(t_room *rooms)
{
	t_room		*room;

	printf("==#|=name==============|============parent=|=x==|=y==|==d=\n");
	if (rooms)
	{
		room = rooms;
		while (room)
		{
			print_room(room);
			room = room->next;
		}
		printf("==========================================================\n");
		return (OK);
	}
	perror("lem-in: Couldn't print rooms 'cause passed argument is NULL.\n");
	printf("==========================================================\n");
	return (KO);
}
