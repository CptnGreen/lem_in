/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rooms_v.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:36 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:36 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		print_rooms_v(t_room *rooms)
{
	t_room		*room;

	if (rooms)
	{
		printf("==#|=name==============|============parent=|=x===|=y===");
		printf("|==d=|=flags=|=ants=inside==============\n");
		room = rooms;
		while (room)
		{
			print_room_v(room);
			room = room->next;
		}
		printf("===|===================|===================|=====|=====");
		printf("=|====|=======|==========================\n");
		return (OK);
	}
	perror("print_rooms_v(): Can't print rooms 'cause passed argument is 0.\n");
	return (KO);
}
