#include "lem-in.h"

t_ant	*dequeue_ant(t_ant_queue **queue)
{
	t_ant_queue	*q;

	if (*queue)
	{
		q = *queue;
		*queue = q->next;
	}
	return (q->ant);
}
