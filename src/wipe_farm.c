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

void	wipe_ants_in_room(t_room *room)
{
	t_ant_queue		*ant;
	t_ant_queue		*prev_ant;

	ant = room->ants;
	while (ant)
	{
		prev_ant = ant;
		ant = ant->next;
		free(prev_ant->ant);
		prev_ant->ant = NULL;
		free(prev_ant);
		prev_ant = NULL;
	}
}

void	wipe_gateways(t_farm *farm)
{
	t_room_queue	*gateway;
	t_room_queue	*prev_gateway;

	gateway = farm->gateways;
	while (gateway)
	{
		prev_gateway = gateway;
		gateway = gateway->next;
		free(prev_gateway);
		prev_gateway = NULL;
	}
}

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
			wipe_ants_in_room(prev_room);
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
	wipe_rooms(farm);
	wipe_gateways(farm);
	wipe_mstr(farm->adj_matrix);
}
