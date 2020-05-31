/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:07:46 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:07:46 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "libftprintf.h"

#define FOUND_SINK 2

int		enqueue_neighbours(t_farm *farm, t_room_queue *q, t_room *r)
{
	int		i;

	i = 0;
	while (i < farm->n_rooms)
	{
		if ((farm->adj_matrix[r->num][i] == '0' || \
			farm->adj_matrix[r->num][i] == '-') && \
			farm->room_ar[i]->d == 0)
		{
			if (!(enqueue_room(&q, farm->room_ar[i])))
				return (KO);
			farm->room_ar[i]->parent = r;
			farm->room_ar[i]->d = 1;
			if (farm->room_ar[i]->is_end)
				return (FOUND_SINK);
		}
		i += 1;
	}
	return (OK);
}

/*
** Called in loop in process_farm_description()
**
** With every call of this function one more (shortest possible)
** path is found via BFS algorythm.
**
** This function also assigns d properties during its
** working process.
*/

int		find_next_path(t_farm *farm)
{
	t_room_queue	*q;
	t_room_queue	*q_tmp;
	t_room			*r;

	r = farm->start_room;
	q = NULL;
	if (!(enqueue_room(&q, r)))
		return (KO);
	q_tmp = q;
	while (q_tmp)
	{
		r = q_tmp->room;
		if (enqueue_neighbours(farm, q_tmp, r) == FOUND_SINK)
			break ;
		q_tmp = q_tmp->next;
	}
	if (choose_path(farm) == FOUND_PATH)
	{
		reset_queue(&q);
		return (FOUND_PATH);
	}
	reset_queue(&q);
	return (NO_MORE_PATHS_FOUND);
}
