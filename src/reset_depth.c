/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_depth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:41 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:41 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		dequeue_room(t_room_queue **queue)
{
	t_room_queue	*q;

	if (*queue)
	{
		q = *queue;
		*queue = q->next;
	}
	return (OK);
}

int		reset_depth(t_room_queue **q)
{
	while (*q)
	{
		if (!((*q)->room->is_chosen || (*q)->room->is_start))
		{
			(*q)->room->parent = NULL;
			(*q)->room->depth = -1;
		}
		dequeue_room(q);
	}
	return (OK);
}
