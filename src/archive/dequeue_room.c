#include "lem-in.h"

int		dequeue_room(t_room_queue **queue)
{
	t_room_queue	*q;

	if (*queue)
	{
		q = *queue;
		*queue = q->next;
	}
	return (OK);
}
