/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_append_room.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:07:57 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:07:58 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*init_room(int num, char const *str, int x, int y)
{
	t_room	*room;

	room = NULL;
	if ((room = (t_room *)ft_memalloc(sizeof(t_room))))
	{
		room->num = num;
		room->name = ((str) ? (ft_strdup(str)) : (NULL));
		room->x = x;
		room->y = y;
		room->n_ants = 0;
		room->next = NULL;
		room->ants = NULL;
		room->d = 0;
		room->is_start = 0;
		room->is_end = 0;
	}
	return (room);
}

/*
** Called from parse_rooms().
** Also checks for duplicates (name or coordinates)
*/

t_room		*init_and_append_room(t_farm *farm, char const *name, int x, int y)
{
	t_room		*room;
	t_room		*prev;

	prev = farm->rooms;
	room = farm->rooms;
	while (room)
	{
		if ((room->x == x && room->y == y) || (ft_strequ(name, room->name)))
		{
			ft_putstr_fd("init_and_append_room(): Duplicate - aborting!\n",
						 farm->log_fd);
			return (NULL);
		}
		prev = room;
		room = room->next;
	}
	room = init_room((farm->n_rooms)++, name, x, y);
	if (farm->rooms)
		prev->next = room;
	else
		farm->rooms = room;
	return (room);
}
