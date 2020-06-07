/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_neighbours_in_rooms.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:07 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:08 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Called from process_input()
**
** This function stores numbers of rooms' neighbours
** in rooms themselves (as arrays) hence reducing time twice.
*/

int		store_neighbours_in_rooms(t_farm *f)
{
	t_room		*r;
	int			i;
	int			n;
	int			neigh[f->n_rooms + 1];

	r = f->rooms;
	while (r)
	{
		i = -1;
		n = -1;
		while (++i < f->n_rooms)
		{
			if (i != r->num && (f->flow_matrix[r->num][i] == '*' || \
								f->flow_matrix[r->num][i] == 'x'))
				neigh[++n] = i;
		}
		if (!(r->neigh_n_ar = (int *)ft_memalloc(sizeof(int) * (n + 2))))
			return (KO);
		r->neigh_n_ar[n + 1] = -1;
		i = -1;
		while (++i <= n)
			r->neigh_n_ar[i] = neigh[i];
		r = r->next;
	}
	return (OK);
}
