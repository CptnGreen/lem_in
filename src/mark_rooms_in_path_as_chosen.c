/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_rooms_in_path_as_chosen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:07:29 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:07:30 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		mark_rooms_in_path_as_chosen(t_farm *farm)
{
	t_room	*r;

	r = farm->end_room;
	if (r->parent)
	{
		r = r->parent;
		enqueue_room(&(farm->gateways), r);
		while (!(r->is_start))
		{
			r->is_chosen = 1;
			r = r->parent;
		}
		return (FOUND_PATH);
	}
	return (NO_MORE_PATHS_FOUND);
}
