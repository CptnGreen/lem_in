/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rooms_queue_v.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:32 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:32 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		print_rooms_queue_v(t_room_queue *queue)
{
	t_room_queue	*q;

	if (queue)
	{
		printf("==#|=name==============|============parent=|=x===|=y===");
		printf("|==d=|=flags=|=ants=inside==============\n");
		q = queue;
		while (q)
		{
			print_room_v(q->room);
			q = q->next;
		}
		printf("===|===================|===================|=====|=====");
		printf("=|====|=======|==========================\n");
		return (OK);
	}
	perror("lem_in: Couldn't print rooms' queue 'cause passed argument is NULL.\n");
	return (KO);
}
