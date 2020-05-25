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

#include "lem-in.h"

int		choose_path(t_farm *farm)
{
	t_room	*r;

	r = farm->end_room;
	if (r->parent)
	{
		/* printf("Last chosen path:\n"); */
		/* printf("==#|=name==============|============parent=|=x===|=y===|==d=|=flags=|\n"); */
		/* print_room_v(r); */
		r = r->parent;
		enqueue_room(&(farm->gateways), r);
		while (!(r->is_start))
		{
			r->is_chosen = 1;
			/* print_room_v(r); */
			r = r->parent;
		}
		/* print_room_v(r); */
		/* printf("===|===================|===================|=====|=====|====|=======|\n"); */
		return (FOUND_PATH);
	}
	return (NO_MORE_PATHS_FOUND);
}
