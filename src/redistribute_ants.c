/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redistribute_ants.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:07 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:08 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** This function returns how much turns (lines) does
** it take to move all the ants from start to finish.
*/

int			redistribute_ants(t_farm *farm)
{
	t_ant			*a;
	t_path			*p;

	a = farm->ants;
	while (a)
	{
		p = farm->paths;
		while (p->next && \
					(p->n_ants_inside + p->gateway_room->d >= \
					p->next->n_ants_inside + p->next->gateway_room->d))
			p = p->next;
		enqueue_ant(&(p->ants), a);
		p->n_ants_inside += 1;
		a = a->next;
	}
	return (p->n_ants_inside + p->gateway_room->d);
}
