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
#include "libft.h"
#include "libftprintf.h"

int			make_ants(t_farm *farm)
{
	int		i;
	t_ant	*a;

	i = 0;
	while (i < farm->n_ants)
	{
		init_and_append_ant(farm, i + 1);
		i += 1;
	}
	a = farm->ants;
	while (a)
	{
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
					enqueue_room(&(farm->gateways), farm->room_ar[i]);
				else
					farm->room_ar[j]->parent = farm->room_ar[i];
			}
			j += 1;
		}
		i += 1;
	}
}

void		calculate_gateway_depth(t_room_queue **gateway)
{
	t_room			*r;
	int				d;

	r = (*gateway)->room;
	d = -1;
	while (!(r->is_start))
	{
		d += 1;
		r = r->parent;
	}
	d = d + 1;
	(*gateway)->n = d;
}

/*
** Called from main()
*/

int			process_farm_description(t_input_line **input, t_farm *farm)
{
	t_room_queue	*gateway;

	if (parse_n_ants(farm, input) != OK || \
		parse_rooms(farm, input) != OK || \
		parse_links(farm, input) != OK)
		return (KO);
	while (find_path(farm) != NO_MORE_PATHS_FOUND)
		;
	build_parents(farm);
	gateway = farm->gateways;
	while (gateway)
	{
		calculate_gateway_depth(&gateway);
		gateway = gateway->next;
	}
	/* print_rooms_v(farm->room_ar[0]); */
	make_ants(farm);
	ft_putstr_fd("process_farm_description(): Success.\n", farm->log_fd);
	return (OK);
}
