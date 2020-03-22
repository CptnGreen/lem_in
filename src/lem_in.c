#include "lem-in.h"

int		move_ant(t_farm *farm, t_room *gateway)
{
	t_room		*r;
	t_ant		*a;

	r = gateway;
	while (1)
	{
		if (r->is_start)
			break ;
		if (r->parent && r->ants == NULL && r->parent->ants != NULL)
		{
			printf("I'm here!\n");
			a = dequeue_ant(&(r->parent->ants));
			enqueue_ant(&(r->ants), a);
			a->room = r;
		}
		r = r->parent;
	}
	print_rooms(farm->rooms);
	return (OK);
}

int		make_move(t_farm *farm)
{
	t_room		*gateway;

	gateway = farm->gateways;
	while (gateway)
	{
		move_ant(farm, gateway);
		gateway = gateway->next;
	}
	return (KO);
}

int		lem_in(t_farm *farm)
{
	int		i;

	/* while (farm->start_room->n_ants != farm->n_ants) */
	/* 	make_move(farm); */
	i = 0;
	while (i < 10)
	{
		make_move(farm);
		printf("----------Move was made----------\n");
		i += 1;
	}
	return (KO);
}
