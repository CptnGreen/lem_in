/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:05 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:06 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define FINISH 2

/*
** Called form make_move()
*/

int		move_ant(t_farm *farm, t_room_queue *gateway, int *was_move)
{
	t_room		*r;
	t_ant		*a;

	farm->end_room->parent = gateway->room;
	r = farm->end_room;
	while (!(r->is_start))
	{
		if ((r->parent) && (r->ants == NULL || r == farm->end_room) && \
			(r->parent->ants != NULL))
		{
			a = dequeue_ant(&(r->parent->ants));
			enqueue_ant(&(r->ants), a);
			printf((*was_move) ? (" ") : (""));
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

/*
** Called form lem-in()
*/

int		make_move(t_farm *farm)
{
	t_room_queue	*gateway;
	t_ant_queue		*a;
	int				i;
	int				was_move;

	gateway = farm->gateways;
	while (gateway)
	{
		was_move = 0;
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

/*
** Called from main()
*/

int		lem_in(t_farm *farm)
{
	if (farm->gateways)
	{
		while (make_move(farm) != FINISH)
			;
		return (OK);
	}
	ft_putstr_fd("lem-in(): No gateways - aborting.\n", farm->log_fd);
	return (KO);
}
