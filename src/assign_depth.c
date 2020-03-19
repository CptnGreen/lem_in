#include "lem-in.h"

int		assign_depth(t_farm *farm)
{
	t_room_queue	*q;
	t_room			*r;
	int				i;

	print_rooms(farm->rooms);
	r = farm->start_room;
	q = NULL;
	if (!(enqueue_room(&q, r)))
		return (KO);
	i = 0;
	while (1)
	{
		if (!(farm->adj_matrix[r->num][i]))
			break ;
		if (farm->adj_matrix[r->num][i] == '1')
		{
			/* print_room(farm->room_ar[i]); */
			if (!(enqueue_room(&q, farm->room_ar[i])))
				return (KO);
		}
		i += 1;
	}
	printf("Current queue:\n");
	print_rooms_queue(q);
	return (OK);
}
