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
#define CONT 3

int		move_ant(t_path *p, t_room **r, int *is_new_line)
{
	t_ant		*a;

	if ((*r)->parent->is_start)
	{
		if (p->ants)
			a = dequeue_ant(&(p->ants));
		else
		{
			*r = (*r)->parent;
			return (CONT);
		}
	}
	else
		a = dequeue_ant(&(*r)->parent->ants);
	enqueue_ant(&((*r)->ants), a);
	ft_printf("%sL%d-%s", \
		(*is_new_line) ? ("") : (" "), a->num, (*r)->name);
	*is_new_line = 0;
	a->room = *r;
	return (OK);
}

/*
** Called from make_move() for each gateway
*/

int		move_ants_along_the_path(t_farm *farm, t_path *p, int *is_new_line)
{
	t_room		*r;

	farm->end_room->parent = p->gateway_room;
	r = farm->end_room;
	while (!(r->is_start))
	{
		if ((r->parent) && \
			(r->ants == NULL || r == farm->end_room) && \
			(r->parent->ants != NULL) && \
			move_ant(p, &r, is_new_line) == CONT)
			continue ;
		r = r->parent;
	}
	if (!(p->next))
		ft_printf("\n");
	return (OK);
}

/*
** Called from lem-in()
*/

int		make_move(t_farm *farm)
{
	t_path			*p;
	t_ant_queue		*a;
	int				i;
	int				is_new_line;

	is_new_line = 1;
	p = farm->paths;
	while (p)
	{
		move_ants_along_the_path(farm, p, &is_new_line);
		p = p->next;
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
	int		n_turns;

	n_turns = 0;
	if (farm->paths)
	{
		while (make_move(farm) != FINISH)
			n_turns += 1;
		return (n_turns + 1);
	}
	ft_putstr_fd("lem-in(): No gateways - aborting.\n", farm->log_fd);
	ft_printf("ERROR\n");
	return (-1);
}
