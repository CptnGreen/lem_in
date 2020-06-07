/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:07:46 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:07:46 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define FOUND_SINK 2

#define ER_FSP1 "enqueue_neighs(): Failed to enqueue room.\n"
#define ER_FSP2 "find_shortest_path(): Failed to enqueue room.\n"

void	reset_rooms(t_farm *farm)
{
	t_room		*r;

	r = farm->rooms;
	while (r)
	{
		r->d = 0;
		r->parent = NULL;
		r = r->next;
	}
}

/*
** Finds room's neighbours (using flow matrix) and
** adds them to the queue
*/

int		enqueue_neighs(t_farm *farm, t_room_queue *q, t_room *r)
{
	int		i;
	int		n;

	i = 0;
	n = r->neigh_n_ar[0];
	while (n != -1)
	{
		if (farm->room_ar[n]->d == 0 && \
			(farm->flow_matrix[r->num][n] == '*' || \
			farm->flow_matrix[r->num][n] == '-'))
		{
			if (!(enqueue_room(&q, farm->room_ar[n])))
			{
				ft_putstr_fd(ER_FSP1, farm->log_fd);
				return (KO);
			}
			farm->room_ar[n]->parent = r;
			farm->room_ar[n]->d = 1;
			if (farm->room_ar[n]->is_end)
				return (FOUND_SINK);
		}
		i += 1;
		n = r->neigh_n_ar[i];
	}
	return (OK);
}

/*
** Called from set_the_stage()
**
** Performs breadth-first search in order to find
** shortest path in current flow matrix constrains
*/

int		find_shortest_path(t_farm *farm)
{
	t_room_queue	*q;
	t_room_queue	*q_tmp;
	int				res;

	reset_rooms(farm);
	q = NULL;
	if (!(enqueue_room(&q, farm->start_room)))
	{
		ft_putstr_fd(ER_FSP2, farm->log_fd);
		return (KO);
	}
	farm->start_room->d = 1;
	q_tmp = q;
	while (q_tmp)
	{
		if ((res = enqueue_neighs(farm, q_tmp, q_tmp->room)) == FOUND_SINK)
		{
			wipe_rooms_queue(&q);
			return ((res == KO) ? (KO) : (FOUND_PATH));
		}
		q_tmp = q_tmp->next;
	}
	wipe_rooms_queue(&q);
	return (NO_MORE_PATHS_FOUND);
}
