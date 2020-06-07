/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flow_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:07:46 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:07:46 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_flow_matrix(t_farm *f)
{
	int		i;
	int		j;

	j = -1;
	while (++j < 3)
	{
		i = -1;
		ft_printf("    |");
		while (++i < f->n_rooms)
			ft_printf("%c", \
				(f->room_ar[i]->name[j]) ? (f->room_ar[i]->name[j]) : (' '));
		ft_printf("|\n");
	}
	ft_printf("----+--------------+----\n");
	i = -1;
	while (f->flow_matrix[++i])
		ft_printf("%4s|%s|%-4s\n", \
							f->room_ar[i]->name, \
							f->flow_matrix[i], \
							f->room_ar[i]->name);
	ft_printf("----+--------------+----\n");
}
