/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:36 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:36 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libftprintf.h"

int		print_paths(t_path *paths)
{
	t_path		*p;
	t_room		*r;
	t_ant_queue	*a;

	p = paths;
	if (p)
	{
		ft_printf("-------------------\n");
		while (p)
		{
			r = p->gateway_room;
			print_room_v(r);
			a = p->ants;
			while (a)
			{
				ft_printf("L%d -> ", a->ant->num);
				a = a->next;
			}
			ft_printf("\n");
			ft_printf("n_ants_inside: %d\n", p->n_ants_inside);
			ft_printf("-------------------\n");
			p = p->next;
		}
		ft_printf("\n\n\n\n\n");
		return (OK);
	}
	perror("print_paths(): Can't print paths 'cause passed argument is 0.\n");
	return (KO);
}
