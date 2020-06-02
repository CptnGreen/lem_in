/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:14 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:15 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

#define NO_LINKS "parse_rooms(): Reached EOF, but no links found - aborting.\n"
#define FOUND_LETTER "parse_rooms(): Letter as the coordinate - aborting.\n"

/*
** Called in handle_new_room()
**
** Checks if there is a letter instead of a digit
** in a room's coordinate field
*/

int			check_coordinates(t_farm *farm, char **split)
{
	int				i;

	i = -1;
	while (split[1][++i])
	{
		if (split[1][i] < '0' || split[1][i] > '9')
		{
			wipe_mstr(split);
			ft_putstr_fd(FOUND_LETTER, farm->log_fd);
			return (KO);
		}
	}
	i = -1;
	while (split[2][++i])
	{
		if (split[2][i] < '0' || split[2][i] > '9')
		{
			wipe_mstr(split);
			ft_putstr_fd(FOUND_LETTER, farm->log_fd);
			return (KO);
		}
	}
	return (OK);
}

int			handle_new_room(t_farm *farm, char **split, int *res)
{
	t_room			*room;

	if (check_coordinates(farm, split) == KO)
		return (KO);
	if ((room = init_and_append_room(\
			farm, split[0], ft_atoi(split[1]), ft_atoi(split[2]))))
	{
		if (*res == START_HEADER)
		{
			*res = 0;
			farm->start_counter += 1;
			room->is_start = 1;
			farm->start_room = room;
		}
		if (*res == END_HEADER)
		{
			*res = 0;
			farm->end_counter += 1;
			room->is_end = 1;
			farm->end_room = room;
		}
		wipe_mstr(split);
		return (OK);
	}
	wipe_mstr(split);
	return (KO);
}

/*
** Called from process_farm_description()
** after parse_n_ants()
*/

int			parse_rooms(t_farm *farm, t_input_line **input)
{
	char			**split;
	int				res;

	if (!(*input))
	{
		ft_putstr_fd("parse_rooms(): Empty map - aborting.\n", farm->log_fd);
		return (KO);
	}
	res = 0;
	while (*input)
	{
		if (check_if_hash(farm, &res, input))
			continue ;
		if (((*input)->line)[0] == '\0' || (((*input)->line)[0]) == 'L')
		{
			ft_putstr_fd("parse_rooms(): Bad line - aborting.\n", farm->log_fd);
			return (KO);
		}
		split = ft_strsplit((*input)->line, ' ');
		if (!split[0] || !split[1] || !split[2] || split[3])
			return ((handle_no_more_rooms(farm, split, &res) == OK) ? OK : KO);
		if ((handle_new_room(farm, split, &res)) == KO)
			return (KO);
		res = 0;
		(*input) = (*input)->next;
	}
	ft_putstr_fd(NO_LINKS, farm->log_fd);
	return (KO);
}
