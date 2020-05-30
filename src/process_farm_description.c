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
		while (p->next && \
				p->n_ants_inside + p->gateway_room->d >= \
				p->next->n_ants_inside + p->next->gateway_room->d)
			p = p->next;
		enqueue_ant(&(p->ants), a);
		p->n_ants_inside += 1;
		enqueue_ant(&(farm->start_room->ants), a);
		a = a->next;
	}
	return (OK);
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
	sort_paths(farm);
	make_ants(farm);
	ft_putstr_fd("process_farm_description(): Success.\n", farm->log_fd);
	return (OK);
}
