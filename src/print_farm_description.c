/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_farm_description.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:17 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:19 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		print_rooms(t_farm *farm)
{
	t_room		*room;

	if (farm->rooms)
	{
		/* room = farm->start_room; */
		/* printf("%s %d %d\n", room->name, room->x, room->y); */
		/* printf("##start\n"); */
		/* room = farm->end_room; */
		/* printf("%s %d %d\n", room->name, room->x, room->y); */
		/* printf("##end\n"); */
		room = farm->rooms;
		while (room)
		{
			if (room->is_start)
				printf("##start\n");
			if (room->is_end)
				printf("##end\n");
			printf("%s %d %d\n", room->name, room->x, room->y);
			room = room->next;
		}
		return (OK);
	}
	perror("lem-in: Couldn't print rooms 'cause passed argument is NULL.\n");
	return (KO);
}

void	print_farm_description(t_farm *farm)
{
	printf("%d\n", farm->n_ants);
	print_rooms(farm);
	print_links(farm->links);
	printf("\n");
}
