#include "lem-in.h"

int		reset_depth(t_room_queue **q)
{
	while (*q)
	{
		if (!((*q)->room->is_chosen || (*q)->room->is_start /* || (*q)->room->is_end */))
		{
			(*q)->room->parent = NULL;
			(*q)->room->depth = -1;
		}
		dequeue_room(q);
	}
	return (OK);
}
