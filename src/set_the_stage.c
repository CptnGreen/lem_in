/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_the_stage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:07 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:08 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Updates flow martix along the shortest path found
** on the previous step
*/

int		update_flow(t_farm *farm)
{
	t_room	*r;

	r = farm->end_room;
	if (r->parent)
	{
		while (!(r->is_start))
		{
			if (farm->flow_matrix[r->parent->num][r->num] == '*')
			{
				farm->flow_matrix[r->parent->num][r->num] = '+';
				farm->flow_matrix[r->num][r->parent->num] = '-';
			}
			else if (farm->flow_matrix[r->parent->num][r->num] == '-')
			{
				farm->flow_matrix[r->parent->num][r->num] = 'x';
				farm->flow_matrix[r->num][r->parent->num] = '*';
			}
			r = r->parent;
		}
		return (OK);
	}
	return (KO);
}

/*
** All the main work happens here
*/

int		set_the_stage(t_farm *farm)
{
	int				res;
	int				n_min_turns;
	int				n_turns;
	char			**m_res;

	n_min_turns = 1000000;
	m_res = NULL;
	while ((res = find_shortest_path(farm)) != NO_MORE_PATHS_FOUND)
	{
		if (res == KO)
			return (KO);
		update_flow(farm);
		rebuild_paths(farm);
		if ((n_turns = redistribute_ants(farm)) >= n_min_turns)
			break ;
		n_min_turns = n_turns;
		wipe_mstr(m_res);
		m_res = mstr_dup(\
			(char const **)farm->flow_matrix, farm->n_rooms, farm->n_rooms);
	}
	wipe_mstr(farm->flow_matrix);
	farm->flow_matrix = m_res;
	rebuild_paths(farm);
	redistribute_ants(farm);
	return (OK);
}
