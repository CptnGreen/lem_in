#include "lem-in.h"

int		enqueue_neighbours(t_farm *farm, t_room_queue *q, t_room *r)
{
	int		i;
	int		d;

	i = 0;
	d = r->depth;
	while (1)
	{
		if (!(farm->adj_matrix[r->num][i]))
			break ;
		if (farm->adj_matrix[r->num][i] == '1' && farm->room_ar[i]->depth == -1)
		{
			if (!(enqueue_room(&q, farm->room_ar[i])))
				return (KO);
			farm->room_ar[i]->parent = r;
			farm->room_ar[i]->depth = d + 1;
		}
		i += 1;
	}
	return (OK);
}

int		dequeue_rooms_with_depth(t_room_queue **queue, int d)
{
	while((*queue)->room->depth == d)
		dequeue_room(queue);
	return (OK);
}

int		assign_depth(t_farm *farm)
{
	t_room_queue	*q;
	t_room_queue	*q_tmp;
	t_room			*r;
	int				d;

	print_rooms(farm->rooms);
	d = 0;
	r = farm->start_room;
	r->depth = d;
	q = NULL;
	if (!(enqueue_room(&q, r)))
		return (KO);
	q_tmp = q;
	while (q_tmp)
	{
		r = q_tmp->room;
		enqueue_neighbours(farm, q_tmp, r);
		q_tmp = q_tmp->next;
	}
	/* dequeue_rooms_with_depth(&q, d); */
	print_rooms_queue(q);
	return (OK);
}
