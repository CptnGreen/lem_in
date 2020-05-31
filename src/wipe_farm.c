/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipe_farm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:07 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:08 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	wipe_rooms(t_farm *farm)
{
	t_room			*room;
	t_room			*prev_room;

	room = farm->rooms;
	if (room)
	{
		while (room)
		{
			prev_room = room;
			room = room->next;
			wipe_ants_queue(&(prev_room->ants));
			ft_strdel(&(prev_room->name));
			prev_room->parent = NULL;
			free(prev_room);
			prev_room = NULL;
		}
		free(farm->room_ar);
		farm->room_ar = NULL;
	}
}

void	wipe_farm(t_farm *farm)
{
	t_ant	*a;
	t_ant	*prev_a;

	wipe_rooms(farm);
	wipe_paths(&(farm->paths));
	if (farm->flow_matrix)
		wipe_mstr(farm->flow_matrix);
	a = farm->ants;
	while (a)
	{
		prev_a = a;
		a = a->next;
		free(prev_a);
		prev_a = NULL;
	}
	farm->ants = NULL;
}
