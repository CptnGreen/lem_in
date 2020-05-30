/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:41 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:41 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		dequeue_room(t_room_queue **queue)
{
	t_room_queue	*q;

	if (*queue)
	{
		q = *queue;
		*queue = q->next;
		free(q);
		q = NULL;
	}
	return (OK);
}

int		reset_queue(t_room_queue **q)
{
	while (*q)
	{
		(*q)->room->parent = NULL;
		(*q)->room->d = 0;
		dequeue_room(q);
	}
	return (OK);
}