/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_append_ant.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:07:54 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:07:55 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant		*init_ant(t_farm *farm, int num)
{
	t_ant	*ant;

	ant = NULL;
	if ((ant = (t_ant *)ft_memalloc(sizeof(t_ant))))
	{
		ant->num = num;
		ant->next = NULL;
		ant->has_moved = 0;
	}
	else
		ft_putstr_fd("Failed to allocate memory for an ant.\n", farm->log_fd);
	return (ant);
}

t_ant		*init_and_append_ant(t_farm *farm, int num)
{
	t_ant		*ant;
	t_ant		*prev;

	prev = farm->ants;
	ant = farm->ants;
	while (ant)
	{
		prev = ant;
		ant = ant->next;
	}
	ant = init_ant(farm, num);
	if (farm->ants)
		prev->next = ant;
	else
		farm->ants = ant;
	return (ant);
}
