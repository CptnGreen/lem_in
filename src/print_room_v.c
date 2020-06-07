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

void	print_room_v(t_room *room)
{
	if (room)
	{
		ft_printf("%5d| %-13s < %13s | %-4d | %-4d | %2d ", room->num, \
				room->name, ((room->parent) ? (room->parent->name) : ("")), \
				room->x, room->y, room->d);
		ft_printf((room->is_start) ? ("| start | ") : (""));
		ft_printf((room->is_end) ? ("|  end  | ") : (""));
	}
}
