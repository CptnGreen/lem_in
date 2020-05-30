/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_farm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:00 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:00 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Called in main()
*/

int		init_farm(t_farm *farm)
{
	if (farm && \
		(farm->log_fd = open(LOG, O_WRONLY | O_APPEND)) >= 0)
	{
		farm->n_ants = 0;
		farm->rooms = NULL;
		farm->start_room = NULL;
		farm->end_room = NULL;
		farm->paths = NULL;
		farm->ants = NULL;
		farm->n_rooms = 0;
		farm->start_counter = 0;
		farm->end_counter = 0;
		farm->adj_matrix = NULL;
		farm->room_ar = NULL;
		ft_putstr_fd("\nLOG:\n================\n", farm->log_fd);
		ft_putstr_fd("init_farm(): Success.\n", farm->log_fd);
		return (OK);
	}
	return (KO);
}
