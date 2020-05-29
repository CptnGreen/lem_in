/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:07:29 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:07:30 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		choose_path(t_farm *farm)
{
	t_room	*r;

	r = farm->end_room;
	if (r->parent)
	{
		/* r = r->parent; */
		while (!(r->is_start))
		{
			if (farm->adj_matrix[r->parent->num][r->num] == '0')
			{
				farm->adj_matrix[r->parent->num][r->num] = '+';
				farm->adj_matrix[r->num][r->parent->num] = '-';
			}
			else if (farm->adj_matrix[r->parent->num][r->num] == '-')
			{
				farm->adj_matrix[r->parent->num][r->num] = '0';
				farm->adj_matrix[r->num][r->parent->num] = '0';
			}
			if (!(r->is_end))
				r->is_chosen = 1;
			r = r->parent;
		}
		return (FOUND_PATH);
	}
	return (NO_MORE_PATHS_FOUND);
}
