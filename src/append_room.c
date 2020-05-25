/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:07:26 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:07:27 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*append_room(t_room **where, t_room *what)
{
	t_room		*room;
	t_room		*prev;

	prev = *where;
	room = *where;
	while (room)
	{
		prev = room;
		room = room->next;
	}
	room = what;
	room->next = NULL;
	if (*where)
		prev->next = room;
	else
		*where = room;
	return (room);
}
