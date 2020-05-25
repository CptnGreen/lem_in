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

#include "lem-in.h"

void	print_room_v(t_room *room)
{
	t_ant_queue		*q;
	int				i;

	if (room)
	{
		printf("%3d| %-17s < %17s | %-3d | %-3d | %2d ", \
			   room->num, room->name, ((room->parent) ? (room->parent->name) : ("")), \
			   room->x, room->y, room->depth);
		if (room->is_start)
			printf("| start | ");
		if (room->is_end)
			printf("|  end  | ");
		if (room->is_chosen)
			printf("|   *   | ");
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
}
