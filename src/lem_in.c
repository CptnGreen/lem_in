#include "lem-in.h"

#define FINISH 2

int		move_ant(t_farm *farm, t_room_queue *gateway)
{
	t_room		*r;
	t_ant		*a;

	farm->end_room->parent = gateway->room;
	r = farm->end_room;
	while (1)
	{
		if (r->is_start)
			break ;
		if (r->parent && (r->ants == NULL || r == farm->end_room) && r->parent->ants != NULL)
		{
			a = dequeue_ant(&(r->parent->ants));
			enqueue_ant(&(r->ants), a);
			printf("L%d-%s ", a->num, r->name);
			a->room = r;
		}
		r = r->parent;
	}
	/* print_rooms(farm->rooms); */
	return (OK);
}

int		make_move(t_farm *farm)
{
	t_room_queue	*gateway;
	t_ant_queue		*a;
	int				i;

	gateway = farm->gateways;
	while (gateway)
	{
		move_ant(farm, gateway);
		gateway = gateway->next;
	}
	printf("\n");
	i = 0;
	a = farm->end_room->ants;
	while (a)
	{
		i += 1;
		a = a->next;
	}
	if (i == farm->n_ants)
		return (FINISH);
	return (OK);
}

int		lem_in(t_farm *farm)
{
	/* print_rooms(farm->rooms); */
	while (1)
	{
		if (make_move(farm) == FINISH)
			break ;
		/* printf("----------Move was made----------\n"); */
	}
	return (KO);
}
