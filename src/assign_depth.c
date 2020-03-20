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
		if (farm->adj_matrix[r->num][i] == '1' && \
			farm->room_ar[i]->depth == -1 && \
			!(farm->room_ar[i]->is_chosen))
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

int		assign_depth(t_farm *farm)
{
	t_room_queue	*q;
	t_room_queue	*q_tmp;
	t_room			*r;
	int				d;

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
	/* print_rooms_queue(q); */
	if (choose_path(farm) == FOUND_PATH && !(farm->end_room->parent->is_start))
	{
		reset_depth(&q);
		return (FOUND_PATH);
	}
	/* print_rooms(farm->rooms); */
	reset_depth(&q);
	return (NO_MORE_PATHS_FOUND);
}
