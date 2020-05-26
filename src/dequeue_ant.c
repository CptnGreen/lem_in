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

#include "lem_in.h"

t_ant	*dequeue_ant(t_ant_queue **queue)
{
	t_ant_queue	*q;
	t_ant		*ant;

	if (*queue)
	{
		q = *queue;
		ant = q->ant;
		*queue = q->next;
		free(q);
		q = NULL;
		return (ant);
	}
	return (NULL);
}
