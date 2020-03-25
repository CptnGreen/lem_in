#include "lem-in.h"

int		print_rooms_v(t_room *rooms)
{
	t_room		*room;

	if (rooms)
	{
		printf("==#|=name==============|============parent=|=x==|=y==|==d=|=flags=|=ants=inside==============\n");
		room = rooms;
		while (room)
		{
			print_room_v(room);
			room = room->next;
		}
		printf("===|===================|===================|====|====|====|=======|==========================\n");
		return (OK);
	}
	perror("lem-in: Couldn't print rooms 'cause passed argument is NULL.\n");
	return (KO);
}
