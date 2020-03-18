#include "lem-in.h"

int		enqueue_room(t_room_queue *queue, t_room *room)
{
	t_room_queue	*q;

	if (room)
	{
		q = queue;
		while (q)
			q = q->next;
		if (!(q = (t_room_queue *)ft_memalloc(sizeof(t_room_queue))))
			return (KO);
		q->room = room;
		q->next = NULL;
		return (OK);
	}
	return (KO);
}
