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
		while (farm->adj_matrix[i][j] && !(farm->room_ar[j]->is_end))
		{
			if (farm->adj_matrix[i][j] == '+')
				farm->room_ar[j]->parent = farm->room_ar[i];
			j += 1;
		}
		i += 1;
	}
}

/*
** Called from main()
*/

int			process_farm_description(t_input_line **input, t_farm *farm)
{
	int		i;

	if (parse_n_ants(farm, input) != OK || \
		parse_rooms(farm, input) != OK || \
		parse_links(farm, input) != OK)
		return (KO);
	while (find_path(farm) != NO_MORE_PATHS_FOUND)
		;
	i = 0;
	while (1)
	{
		if (!(farm->adj_matrix[farm->end_room->num][i]))
			break ;
		if (farm->adj_matrix[farm->end_room->num][i] == '-')
		{
			enqueue_room(&(farm->gateways), farm->room_ar[i]);
		}
		i += 1;
	}
	build_parents(farm);
	print_rooms_v(farm->room_ar[0]);
	make_ants(farm);
	ft_putstr_fd("process_farm_description(): Success.\n", farm->log_fd);
	return (OK);
}
