/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebuild_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:38 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:38 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		investigate_shortest_path(\
				t_path *p, t_path **shortest_path, t_room **new_gateway)
{
	int				d_min;

	d_min = 1000000;
	while (p)
	{
		if (p->gateway_room->d <= d_min && !(p->is_sorted))
		{
			d_min = p->gateway_room->d;
			*new_gateway = p->gateway_room;
			*shortest_path = p;
		}
		p = p->next;
	}
}

void		recalculate_paths_depths(t_farm *farm)
{
	t_room			*r;
	int				d;
	t_path			*p;

	p = farm->paths;
	while (p)
	{
		r = p->gateway_room;
		d = -1;
		while (!(r->is_start))
		{
			d += 1;
			r = r->parent;
		}
		r = p->gateway_room;
		d = d + 1;
		while (!(r->is_start))
		{
			r->d = d / 2;
			d -= 1;
			r = r->parent;
		}
		r->d = 0;
		p = p->next;
	}
}

void		rebuild_parents(t_farm *farm)
{
	int		i;
	int		n;
	t_room	*r;

	r = farm->rooms;
	while (r)
	{
		i = 0;
		n = r->neigh_n_ar[0];
		while (n != -1)
		{
			if (farm->flow_matrix[r->num][n] == '+')
			{
				if (farm->room_ar[n]->is_end)
					init_and_append_path(farm, farm->room_ar[r->num]);
				else
					farm->room_ar[n]->parent = r;
			}
			n = r->neigh_n_ar[++i];
		}
		r = r->next;
	}
}

/*
** Called from set_the_stage()
*/

void		rebuild_paths(t_farm *farm)
{
	t_path			*shortest_path;
	t_path			*p_u;
	t_room			*new_gateway;

	wipe_paths(&(farm->paths));
	farm->paths = NULL;
	rebuild_parents(farm);
	recalculate_paths_depths(farm);
	p_u = farm->paths;
	farm->paths = NULL;
	new_gateway = NULL;
	while (1)
	{
		investigate_shortest_path(p_u, &shortest_path, &new_gateway);
		if (!new_gateway)
			break ;
		init_and_append_path(farm, new_gateway);
		shortest_path->is_sorted = 1;
		new_gateway = NULL;
		shortest_path = NULL;
	}
	wipe_paths(&p_u);
	p_u = NULL;
}
