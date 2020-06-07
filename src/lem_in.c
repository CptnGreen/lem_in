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

void	print_move(int new_line, t_ant *a, t_room *r)
{
	ft_putstr((new_line) ? ("") : (" "));
	ft_putchar('L');
	ft_putnbr(a->num);
	ft_putchar('-');
	ft_putstr(r->name);
}

int		move_ant(t_path *p, t_room *r, t_room *heir, int *new_line)
{
	t_ant		*a;

	a = NULL;
	if (r->parent->is_start)
	{
		if (p->ants && (a = dequeue_ant(&(p->ants))))
		{
			enqueue_ant(&(r->ants), a);
			print_move(*new_line, a, r);
			a->has_moved = 1;
			*new_line = 0;
		}
		else
			return (CONT);
	}
	else if (r->is_dupl && (a = dequeue_ant(&(r->parent->ants))))
	{
		enqueue_ant(&(heir->ants), a);
		print_move(*new_line, a, heir);
		a->has_moved = 1;
		*new_line = 0;
	}
	return (OK);
}

/*
** Called from make_move() for each gateway
*/

int		move_ants_along_the_path(t_farm *farm, t_path *p, int *is_new_line)
{
	t_room		*r;
	t_room		*heir;
	int			new_line;

	farm->end_room->parent = p->gateway_room;
	r = farm->end_room;
	heir = r;
	new_line = *is_new_line;
	while (!(r->is_start))
	{
		if (((r->parent) && \
				(r->ants == NULL || r == farm->end_room) && \
				((!(r->parent->is_start) && r->parent->ants != NULL) || \
				(r->parent->is_start && p->ants != NULL))) && \
			(move_ant(p, r, heir, &new_line) == CONT))
		{
			heir = r;
			r = r->parent;
			continue ;
		}
		heir = r;
		r = r->parent;
	}
	*is_new_line = new_line;
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

	p = farm->paths;
	is_new_line = 1;
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
	t_ant	*a;

	n_turns = 0;
	if (farm->paths)
	{
		while (make_move(farm) != FINISH)
		{
			n_turns += 1;
			a = farm->ants;
			while (a)
			{
				a->has_moved = 0;
				a = a->next;
			}
			ft_putchar('\n');
		}
		ft_putchar('\n');
		return (n_turns + 1);
	}
	ft_putstr_fd("lem_in(): No gateways, aborting.\n", farm->log_fd);
	return (KO);
}
