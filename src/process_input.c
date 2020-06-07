/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:07 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:08 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Creates ants' list attached to =farm= object
**
** This list is then used to create ants' queues when
** distributing ants between found paths
*/

int		make_ants(t_farm *farm)
{
	int		i;

	i = 0;
	if (farm->n_ants > 0)
	{
		while (i < farm->n_ants)
		{
			init_and_append_ant(farm, i + 1);
			i += 1;
		}
		return (OK);
	}
	ft_putstr_fd("make_ants(): n_ants <= 0.\n", farm->log_fd);
	return (KO);
}

int		print_input(t_farm *farm, t_input_line *input)
{
	if (input)
	{
		while (input)
		{
			ft_putendl(input->line);
			input = input->next;
		}
		ft_putchar('\n');
		return (OK);
	}
	ft_putstr_fd("print_input(): Input is NULL.\n", farm->log_fd);
	return (KO);
}

/*
** Checks for incorrect input happens here
*/

int		parse_input(t_farm *farm, t_input_line **input)
{
	if (parse_n_ants(farm, input) != OK || \
		parse_rooms(farm, input) != OK || \
		parse_links(farm, input) != OK)
		return (KO);
	ft_putstr_fd("parse_input(): Success.\n", farm->log_fd);
	return (OK);
}

/*
** Called from main()
**
** Program reads all input data redirected to it into a list and
** then prints it immediately without analysis.
**
** TODO: (?) consider adding protection against infinite input
** such as from =/dev/random=, =/dev/urandom= or =/dev/zero=
*/

int		process_input(t_farm *farm)
{
	t_input_line	*input;
	t_input_line	*input_start;

	input_start = NULL;
	if (init_farm(farm) && \
		get_input(farm, FD, &input_start))
	{
		input = input_start;
		if (print_input(farm, input) && \
			parse_input(farm, &input) && \
			store_neighbours_in_rooms(farm) && \
			make_ants(farm))
		{
			wipe_input(&input_start);
			ft_putstr_fd("process_input(): Success.\n", farm->log_fd);
			return (OK);
		}
	}
	wipe_input(&input_start);
	ft_putstr_fd("process_input(): Aborting.\n", farm->log_fd);
	return (KO);
}
