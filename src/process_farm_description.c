/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_farm_description.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:38 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:38 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Called from main()
*/

int			process_farm_description(t_input_line **input, t_farm *farm)
{
	t_input_line	**input_start;

	input_start = input;
	if (parse_n_ants(farm, input) != OK || \
		parse_rooms(farm, input) != OK || \
		parse_links(farm, input) != OK)
	{
		wipe_input(input_start);
		wipe_farm(farm);
		ft_printf("ERROR\n");
		exit(1);
	}
	ft_putstr_fd("process_farm_description(): Success.\n", farm->log_fd);
	return (OK);
}
