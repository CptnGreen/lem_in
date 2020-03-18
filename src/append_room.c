#include "lem-in.h"

t_room		*append_room(t_farm *farm, char const *name, int x, int y)
{
	t_room		*room;
	t_room		*prev;

	prev = farm->rooms;
	room = farm->rooms;
	while (room)
	{
		prev = room;
		room = room->next;
	}
	room = init_room((farm->n_rooms)++, name, x, y);
	if (farm->rooms)
		prev->next = room;
	else
		farm->rooms = room;
	return (room);
}
