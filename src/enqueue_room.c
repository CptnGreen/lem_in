/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:07:39 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:07:40 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		handle_empty_rooms_queue(t_room_queue **queue, t_room *room)
{
	if (!(*queue = (t_room_queue *)ft_memalloc(sizeof(t_room_queue))))
		return (KO);
	(*queue)->room = room;
	(*queue)->n = 0;
	(*queue)->next = NULL;
	return (OK);
}

int		enqueue_room(t_room_queue **queue, t_room *room)
{
	t_room_queue	*q;
	t_room_queue	*prev;

	if (room)
	{
		if (!(*queue))
			return (handle_empty_rooms_queue(queue, room));
		q = *queue;
		while (q)
		{
			prev = q;
			q = q->next;
		}
		if (!(q = (t_room_queue *)ft_memalloc(sizeof(t_room_queue))))
			return (KO);
		prev->next = q;
		q->room = room;
		q->n = prev->n + 1;
		q->next = NULL;
		return (OK);
	}
	return (KO);
}
