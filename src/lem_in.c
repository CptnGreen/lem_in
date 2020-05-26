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

int		move_ants(t_farm *farm, t_room_queue *gateway)
{
	t_room		*r;
	t_ant		*a;
	int			was_move_on_path;

	was_move_on_path = 0;
	farm->end_room->parent = gateway->room;
	r = farm->end_room;
	while (!(r->is_start))
	{
		if ((r->parent) && (r->ants == NULL || r == farm->end_room) && \
			(r->parent->ants != NULL))
		{
			a = dequeue_ant(&(r->parent->ants));
			enqueue_ant(&(r->ants), a);
			printf("%s%sL%d-%s", \
				((!was_move_on_path && gateway != farm->gateways) ? " " : ""), \
				(was_move_on_path ? " " : ""), a->num, r->name);
			was_move_on_path = ((was_move_on_path == 0) ? 1 : was_move_on_path);
			a->room = r;
		}
		r = r->parent;
	}
	if (!(gateway->next))
		printf("\n");
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

	gateway = farm->gateways;
	while (gateway)
	{
		move_ants(farm, gateway);
		gateway = gateway->next;
	}
	a = farm->end_room->ants;
	i = 0;
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
