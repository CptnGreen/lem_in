/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants_v.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:30 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:30 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define SHOW_ANTS 5

void	print_ants(t_room *room)
{
	int				i;
	t_ant_queue		*q;

	q = room->ants;
	i = 0;
	while (q)
	{
		ft_printf("L%d ", q->ant->num);
		i += 1;
		if (i > SHOW_ANTS - 1)
		{
			ft_printf("...");
			break ;
		}
		q = q->next;
	}
	ft_printf("\n");
}
