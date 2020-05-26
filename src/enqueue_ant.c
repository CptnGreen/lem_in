/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue_ant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:06:57 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:07:01 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		handle_empty_ants_queue(t_ant_queue **queue, t_ant *ant)
{
	if (!(*queue = (t_ant_queue *)ft_memalloc(sizeof(t_ant_queue))))
		return (KO);
	(*queue)->ant = ant;
	(*queue)->next = NULL;
	return (OK);
}

/*
** Called in lem-in()->move_ants_along_the_path()
*/

int		enqueue_ant(t_ant_queue **queue, t_ant *ant)
{
	t_ant_queue	*q;
	t_ant_queue	*prev;

	if (ant)
	{
		if (!(*queue))
			return (handle_empty_ants_queue(queue, ant));
		q = *queue;
		while (q)
		{
			prev = q;
			q = q->next;
		}
		if (!(q = (t_ant_queue *)ft_memalloc(sizeof(t_ant_queue))))
			return (KO);
		prev->next = q;
		q->ant = ant;
		q->next = NULL;
		return (OK);
	}
	return (KO);
}
