/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_ant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 02:57:44 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:06:39 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_ant	*dequeue_ant(t_ant_queue **queue)
{
	t_ant_queue	*q;

	q = NULL;
	if (*queue)
	{
		q = *queue;
		*queue = q->next;
	}
	return (q->ant);
}
