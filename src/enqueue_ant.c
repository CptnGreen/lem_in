#include "lem-in.h"

int		enqueue_ant(t_ant_queue **queue, t_ant *ant)
{
	t_ant_queue	*q;
	t_ant_queue	*prev;

	if (ant)
	{
		if (!(*queue))
		{
			if (!(*queue = (t_ant_queue *)ft_memalloc(sizeof(t_ant_queue))))
				return (KO);
			(*queue)->ant = ant;
			(*queue)->next = NULL;
			return (OK);
		}
		q = *queue;
		while (q)
		{
			prev = q;
			q = q->next;
		}
		if (!(q = (t_ant_queue *)ft_memalloc(sizeof(t_ant_queue))))
			return (KO);
		prev->next = q;
		q->ant = ant;
		q->next = NULL;
		return (OK);
	}
	return (KO);
}
