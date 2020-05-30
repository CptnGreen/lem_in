/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_farm_description.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:38 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:38 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			make_ants(t_farm *farm)
{
	int				i;
	t_ant			*a;
	t_path			*p;

	i = 0;
	while (i < farm->n_ants)
	{
		init_and_append_ant(farm, i + 1);
		i += 1;
	}
	a = farm->ants;
	while (a)
	{
		p = farm->paths;
		while (p->next)
		{
			/* print_paths(farm->paths); */
			if (p->n_ants_inside + p->gateway_room->d > \
				p->next->n_ants_inside + p->next->gateway_room->d)
			{
				p = p->next;
				continue ;
			}
			enqueue_ant(&(p->ants), a);
			p->n_ants_inside += 1;
			break ;
		}
		enqueue_ant(&(farm->start_room->ants), a);
		a = a->next;
	}
	return (OK);
}

void		build_parents(t_farm *farm)
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

void		sort_paths(t_farm *farm)
{
	t_path			*path;
	t_path			*p_u;
	t_path			*p;
	int				d_min;
	t_room			*r;

	p_u = farm->paths;
	farm->paths = NULL;
	r = NULL;
	while (1)
	{
		p = p_u;
		d_min = 1000000;
		while (p)
		{
			if (p->gateway_room->d <= d_min && !(p->is_sorted))
			{
				d_min = p->gateway_room->d;
				r = p->gateway_room;
				path = p;
			}
			p = p->next;
		}
		if (r)
		{
			init_and_append_path(farm, r);
			path->is_sorted = 1;
			r = NULL;
		}
		else
		{
			/* print_paths(farm->paths); */
			return ;
		}
	}
}

/*
** Called from main()
*/

int			process_farm_description(t_input_line **input, t_farm *farm)
{
	if (parse_n_ants(farm, input) != OK || \
		parse_rooms(farm, input) != OK || \
		parse_links(farm, input) != OK)
		return (KO);
	while (find_path(farm) != NO_MORE_PATHS_FOUND)
		;
	build_parents(farm);
	calculate_paths_depths(farm);
	sort_paths(farm);
	make_ants(farm);
	print_paths(farm->paths);
	print_rooms_v(farm->room_ar[0]);
	ft_putstr_fd("process_farm_description(): Success.\n", farm->log_fd);
	return (OK);
}
