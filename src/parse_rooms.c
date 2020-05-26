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

#define AR_BUILT "build_room_ar(): Array of rooms is built.\n"
#define NO_LINKS "parse_rooms(): Reached EOF, but no links found - aborting.\n"
#define FOUND_LETTER "parse_rooms(): Letter as the coordinate - aborting.\n"
#define MANY_COORDS "parse_rooms(): Too many coords given - aborting.\n"
#define ROOMS_END "handle_no_more_rooms(): End of rooms' declarations. Starts: "
#define WRONG_NUM "handle_no_more_rooms(): Starts/ends wrong num - aborting.\n"
#define ADJ_INIT "handle_no_more_rooms(): Adjacency matrix initialized.\n"

/*
** Called in handle_no_more_rooms()
*/

int			build_room_ar(t_farm *farm)
{
	t_room		*room;

	room = farm->rooms;
	if (!(farm->room_ar = \
		(t_room **)ft_memalloc(sizeof(t_room *) * (farm->n_rooms + 1))))
		return (KO);
	while (room)
	{
		farm->room_ar[room->num] = room;
		room = room->next;
	}
	farm->room_ar[farm->n_rooms] = NULL;
	ft_putstr_fd(AR_BUILT, farm->log_fd);
	return (OK);
}

int			handle_no_more_rooms(t_farm *farm, char **split, char **line)
{
	if (split[0] && split[1] && split[2] && split[3])
	{
		ft_putstr_fd(MANY_COORDS, farm->log_fd);
		return (KO);
	}
	wipe_mstr(split);
	ft_putstr_fd(ROOMS_END, farm->log_fd);
	ft_putnbr_fd(farm->start_counter, farm->log_fd);
	ft_putstr_fd(", ends: ", farm->log_fd);
	ft_putnbr_fd(farm->end_counter, farm->log_fd);
	ft_putstr_fd("\n", farm->log_fd);
	if (farm->start_counter != 1 || farm->end_counter != 1)
	{
		ft_putstr_fd(WRONG_NUM, farm->log_fd);
		ft_strdel(line);
		return (KO);
	}
	if (!(farm->adj_matrix = get_matrix_of_char(\
				farm->n_rooms, farm->n_rooms, '0')) || \
		build_room_ar(farm) == KO)
		return (KO);
	farm->end_room->n_ants = farm->n_ants;
	ft_putstr_fd(ADJ_INIT, farm->log_fd);
	return (OK);
}

/*
** Called in handle_new_room()
*/

int			check_coordinates(t_farm *farm, char **split, char **line)
{
	int				i;

	ft_strdel(line);
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

int			handle_new_room(t_farm *farm, char **split, int res, char **line)
{
	t_room			*room;

	if (check_coordinates(farm, split, line) == KO)
		return (KO);
	if ((room = init_and_append_room(\
			farm, split[0], ft_atoi(split[1]), ft_atoi(split[2]))))
	{
		if (res == FOUND_START)
		{
			farm->start_counter += 1;
			room->is_start = 1;
			farm->start_room = room;
		}
		if (res == FOUND_END)
		{
			farm->end_counter += 1;
			room->is_end = 1;
			farm->end_room = room;
		}
	}
	ft_strdel(line);
	wipe_mstr(split);
	return (OK);
}

/*
** Called from process_farm_description()
** after parse_n_ants()
*/

int			parse_rooms(t_farm *farm, t_input_line **input)
{
	char			**split;
	int				res;
	char			*line;

	res = 0;
	while (*input)
	{
		line = ft_strdup((*input)->line);
		if (line[0] == '#')
		{
			res = handle_start_and_end_headers(farm, &line);
			(*input) = (*input)->next;
			continue ;
		}
		split = ft_strsplit(line, ' ');
		if (!split[0] || !split[1] || !split[2] || split[3])
			return ((handle_no_more_rooms(farm, split, &line) == OK) ? OK : KO);
		if (handle_new_room(farm, split, res, &line) == KO)
			return (KO);
		res = 0;
		(*input) = (*input)->next;
	}
	ft_putstr_fd(NO_LINKS, farm->log_fd);
	ft_strdel(&line);
	return (KO);
}
