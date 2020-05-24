#include "lem-in.h"

#define FINISH 2

int		move_ant(t_farm *farm, t_room_queue *gateway, int *was_move)
{
	t_room		*r;
	t_ant		*a;

	farm->end_room->parent = gateway->room;
	r = farm->end_room;
	*was_move = 0;
	while (!(r->is_start))
	{
		if (r->parent && \
			(r->ants == NULL || r == farm->end_room) && \
			r->parent->ants != NULL)
		{
			a = dequeue_ant(&(r->parent->ants));
			enqueue_ant(&(r->ants), a);
			if (*was_move)
				printf(" ");
			*was_move = 0;
			printf("L%d-%s", a->num, r->name);
			*was_move = 1;
			a->room = r;
		}
		r = r->parent;
	}
	if (!(gateway->next))
	{
		*was_move = 0;
		printf("\n");
	}
	return (OK);
}

int		make_move(t_farm *farm)
{
	t_room_queue	*gateway;
	t_ant_queue		*a;
	int				i;
	int				was_move;

	gateway = farm->gateways;
	was_move = 0;
	while (gateway)
	{
		move_ant(farm, gateway, &was_move);
		if (was_move)
			printf(" ");
		gateway = gateway->next;
	}
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
	while (make_move(farm) != FINISH)
		;
	return (OK);
}
