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

void	print_path(t_path *p)
{
	t_room		*r;
	t_ant_queue	*a;
	int			i;

	r = p->gateway_room;
	print_room_v(r);
	ft_printf("| (%4d): ", p->n_ants_inside);
	a = p->ants;
	i = 0;
	while (a)
	{
		ft_printf("L%d ", a->ant->num);
		a = a->next;
		i += 1;
		if (i >= 4)
		{
			ft_printf("...");
			break ;
		}
	}
	ft_printf("\n");
	p = p->next;
}

int		print_paths(t_path *paths)
{
	t_path		*p;

	p = paths;
	if (p)
	{
		while (p)
			print_path(p);
		ft_printf("===|===================|===================|=====|=====");
		ft_printf("|====|=======|==========================\n");
		return (OK);
	}
	perror("print_paths(): Can't print paths 'cause passed argument is 0.\n");
	return (KO);
}
