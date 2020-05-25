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

#include "lem-in.h"

int		enqueue_room(t_room_queue **queue, t_room *room)
{
	t_room_queue	*q;
	t_room_queue	*prev;

	if (room)
	{
		if (!(*queue))
		{
			if (!(*queue = (t_room_queue *)ft_memalloc(sizeof(t_room_queue))))
				return (KO);
			(*queue)->room = room;
			(*queue)->next = NULL;
			return (OK);
		}
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
		q->next = NULL;
		return (OK);
	}
	return (KO);
}
