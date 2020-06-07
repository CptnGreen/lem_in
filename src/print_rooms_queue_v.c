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
		ft_printf("==#|=name==============|============parent=|=x===|=y===");
		ft_printf("|==d=|=flags=|=ants=inside==============\n");
		q = queue;
		while (q)
		{
			print_room_v(q->room);
			q = q->next;
		}
		ft_printf("===|===================|===================|=====|=====");
		ft_printf("|====|=======|==========================\n");
		return (OK);
	}
	perror("print_rooms_queue_v(): Passed argument is NULL - can't print.\n");
	return (KO);
}
