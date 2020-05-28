/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:07:46 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:07:46 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		enqueue_neighbours(t_farm *farm, t_room_queue *q, t_room *r)
{
	int		i;
	int		d;

	i = 0;
	d = r->depth;
	while (1)
	{
		if (i >= farm->n_rooms)
			break ;
		if (farm->adj_matrix[r->num][i] == '1' && \
			farm->room_ar[i]->depth == -1 && \
			!(farm->room_ar[i]->is_chosen))
		{
			if (!(enqueue_room(&q, farm->room_ar[i])))
				return (KO);
			farm->room_ar[i]->parent = r;
			farm->room_ar[i]->depth = d + 1;
		}
		i += 1;
	}
	return (OK);
}

/*
** Called in loop in process_farm_description()
**
** With every call of this function one more path is found.
** It assigns depths to rooms during its working process.
*/

int		find_path(t_farm *farm)
{
	t_room_queue	*q;
	t_room_queue	*q_tmp;
	t_room			*r;

	r = farm->start_room;
	r->depth = 0;
	q = NULL;
	if (!(enqueue_room(&q, r)))
		return (KO);
	q_tmp = q;
	while (q_tmp)
	{
		r = q_tmp->room;
		enqueue_neighbours(farm, q_tmp, r);
		q_tmp = q_tmp->next;
	}
	if (choose_path(farm) == FOUND_PATH && !(farm->end_room->parent->is_start))
	{
		reset_depth(&q);
		return (FOUND_PATH);
	}
	reset_depth(&q);
	return (NO_MORE_PATHS_FOUND);
}
