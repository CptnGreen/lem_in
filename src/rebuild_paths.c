/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebuild_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:38 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:38 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		rebuild_parents(t_farm *farm)
{
	int		i;
	int		j;

	i = 0;
	while (farm->adj_matrix[i])
	{
		j = 0;
		while (farm->adj_matrix[i][j])
		{
			if (farm->adj_matrix[i][j] == '+')
			{
				if (farm->room_ar[j]->is_end)
					init_and_append_path(farm, farm->room_ar[i]);
				else
					farm->room_ar[j]->parent = farm->room_ar[i];
			}
			j += 1;
		}
		i += 1;
	}
}

void		calculate_paths_depths(t_farm *farm)
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
			r->d = d;
			d -= 1;
			r = r->parent;
		}
		r->d = 0;
		p = p->next;
	}
}

void		investigate_shortest_path(t_path *p, t_path **path, t_room **r)
{
	int				d_min;

	d_min = 1000000;
	while (p)
	{
		if (p->gateway_room->d <= d_min && !(p->is_sorted))
		{
			d_min = p->gateway_room->d;
			*r = p->gateway_room;
			*path = p;
		}
		p = p->next;
	}
}

void		rebuild_paths(t_farm *farm)
{
	t_path			*path;
	t_path			*p_u;
	t_room			*r;

	wipe_paths(&(farm->paths));
	farm->paths = NULL;
	rebuild_parents(farm);
	calculate_paths_depths(farm);
	p_u = farm->paths;
	farm->paths = NULL;
	r = NULL;
	while (1)
	{
		investigate_shortest_path(p_u, &path, &r);
		if (r)
		{
			init_and_append_path(farm, r);
			path->is_sorted = 1;
			r = NULL;
		}
		else
		{
			wipe_paths(&p_u);
			p_u = NULL;
			return ;
		}
	}
}
