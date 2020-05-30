/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_append_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:07:57 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:07:58 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path		*init_path(t_room *gateway_room)
{
	t_path	*path;

	path = NULL;
	if ((path = (t_path *)ft_memalloc(sizeof(t_path))))
	{
		path->n_ants_inside = 0;
		path->next = NULL;
		path->ants = NULL;
		path->gateway_room = gateway_room;
	}
	return (path);
}

t_path		*init_and_append_path(t_farm *farm, t_room *gateway_room)
{
	t_path		*path;
	t_path		*prev;

	prev = farm->paths;
	path = farm->paths;
	while (path)
	{
		prev = path;
		path = path->next;
	}
	path = init_path(gateway_room);
	if (farm->paths)
		prev->next = path;
	else
		farm->paths = path;
	return (path);
}
