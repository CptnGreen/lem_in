/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_no_more_rooms.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:14 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:15 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define AR_BUILT "build_room_ar(): Array of rooms is built.\n"
#define MANY_COORDS "parse_rooms(): Too many coords given - aborting.\n"
#define ROOMS_END "handle_no_more_rooms(): End of rooms' declarations. Starts: "
#define WRONG_NUM "handle_no_more_rooms(): Starts/ends wrong num - aborting.\n"
#define ADJ_INIT "handle_no_more_rooms(): Adjacency matrix initialized.\n"

/*
** Called in handle_no_more_rooms()
**
** I need my rooms' list's nodes to be organized consequently (as an array)
** but i can't start forming this array before i know an exact number of rooms
** so i first build a regular list and then move it to the array.
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

void		log_starts_and_ends(t_farm *farm)
{
	ft_putstr_fd(ROOMS_END, farm->log_fd);
	ft_putnbr_fd(farm->start_counter, farm->log_fd);
	ft_putstr_fd(", ends: ", farm->log_fd);
	ft_putnbr_fd(farm->end_counter, farm->log_fd);
	ft_putstr_fd("\n", farm->log_fd);
}

/*
** Adjacency matrix initialization happens here
*/

int			handle_no_more_rooms(t_farm *farm, char **split, char **line)
{
	if (split[0] && split[1] && split[2] && split[3])
	{
		ft_strdel(line);
		wipe_mstr(split);
		ft_putstr_fd(MANY_COORDS, farm->log_fd);
		return (KO);
	}
	wipe_mstr(split);
	log_starts_and_ends(farm);
	if (farm->start_counter != 1 || farm->end_counter != 1)
	{
		ft_putstr_fd(WRONG_NUM, farm->log_fd);
		ft_strdel(line);
		return (KO);
	}
	if (!(farm->adj_matrix = get_matrix_of_char(\
		farm->n_rooms, farm->n_rooms, 'x')) || build_room_ar(farm) == KO)
	{
		ft_strdel(line);
		return (KO);
	}
	farm->end_room->n_ants = farm->n_ants;
	ft_putstr_fd(ADJ_INIT, farm->log_fd);
	ft_strdel(line);
	return (OK);
}
