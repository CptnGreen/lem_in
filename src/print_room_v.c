/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_room_v.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:30 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:30 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_ants(t_room *room)
{
	int				i;
	t_ant_queue		*q;

	q = room->ants;
	i = 0;
	while (q)
	{
		printf("L%d ", q->ant->num);
		i += 1;
		if (i > 10)
		{
			printf("...");
			break ;
		}
		q = q->next;
	}
	printf("\n");
}

void	print_room_v(t_room *room)
{
	if (room)
	{
		printf("%3d| %-17s < %17s | %-3d | %-3d | %2d ", room->num, \
				room->name, ((room->parent) ? (room->parent->name) : ("")), \
				room->x, room->y, room->depth);
		printf((room->is_start) ? ("| start | ") : (""));
		printf((room->is_end) ? ("|  end  | ") : (""));
		printf((room->is_chosen) ? ("|   *   | ") : (""));
		print_ants(room);
	}
}
