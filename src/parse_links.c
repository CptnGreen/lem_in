/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:10 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:11 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define LOOP_LINK "check_link(): Loop-link found - aborting.\n"
#define BAD_LINK "check_link(): Bad link found - aborting.\n"

#define END_OF_INPUT 5

/*
** Called in append_link()
** Checks for:
** (1) loop-links (like "room-room"),
** (2) links pointing to missing rooms.
**
** Puts '0's instead of 'x's in adjacency matrix to
** mark connections between rooms.
*/

int		check_link(t_farm *farm, char const *src, char const *dst)
{
	t_room	*room;
	t_room	*room_src;
	t_room	*room_dst;

	if (ft_strequ(src, dst))
		return (KO);
	room_src = NULL;
	room_dst = NULL;
	room = farm->room_ar[0];
	while (room)
	{
		room_src = ((!room_src && ft_strequ(src, room->name)) ? \
					room : room_src);
		room_dst = ((!room_dst && ft_strequ(dst, room->name)) ? \
					room : room_dst);
		if (room_src && room_dst)
		{
			farm->flow_matrix[room_src->num][room_dst->num] = '0';
			farm->flow_matrix[room_dst->num][room_src->num] = '0';
			return (OK);
		}
		room = room->next;
	}
	return (KO);
}

/*
** Checks if link consists of exactly 2 parts
*/

int		parse_next_link(t_farm *farm, t_input_line **input)
{
	char		**split;

	while (((*input)->line)[0] == '#')
	{
		*input = (*input)->next;
		if (!(*input))
			return (END_OF_INPUT);
		if (((*input)->line)[0] == '\0')
			return (KO);
	}
	split = ft_strsplit((*input)->line, '-');
	if (!split[0] || !split[1] || split[2])
	{
		wipe_mstr(split);
		ft_putstr_fd(BAD_LINK, farm->log_fd);
		return (KO);
	}
	if (check_link(farm, split[0], split[1]) != OK)
	{
		ft_putstr_fd(BAD_LINK, farm->log_fd);
		wipe_mstr(split);
		return (KO);
	}
	wipe_mstr(split);
	return (OK);
}

/*
** This function is called in process_farm_description()
** after parse_n_ants() and parse_rooms().
*/

int		parse_links(t_farm *farm, t_input_line **input)
{
	int		res;

	if (*input)
	{
		while (*input)
		{
			if ((res = parse_next_link(farm, input)) == END_OF_INPUT)
				break ;
			else if (res == KO)
			{
				return (KO);
			}
			*input = (*input)->next;
		}
		ft_putstr_fd("parse_links(): End of input - continue.\n", farm->log_fd);
		return (OK);
	}
	ft_putstr_fd("parse_links(): No links found - aborting.\n", farm->log_fd);
	return (KO);
}
