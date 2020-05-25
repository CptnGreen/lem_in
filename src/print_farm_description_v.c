/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_farm_description_v.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:25 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:25 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_farm_description_v(t_farm *farm)
{
	/*
	** print_mstr(farm->adj_matrix);
	*/
	printf("Gateways - last rooms (except for \"end\") in the found paths:\n");
	print_rooms_queue_v(farm->gateways);
	printf("\n");
}
