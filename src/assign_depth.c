#include "lem-in.h"

int		assign_depth(t_farm *farm)
{
	t_room_queue	*q;

	print_rooms(farm->rooms);
	q = NULL;
	if (!(enqueue_room(q, farm->start_room)))
		return (KO);
	return (OK);
}
