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

void	print_input(t_input_line *input_seed)
{
	t_input_line	*input;

	input = input_seed;
	while (input)
	{
		ft_printf("%s\n", input->line);
		input = input->next;
	}
	ft_printf("\n");
	return ;
}

int		process_input(t_farm *farm)
{
	t_input_line	*input;
	t_input_line	*input_start;

	if (init_farm(farm) && \
		get_input(farm, FD, &input))
	{
		input_start = input;
		print_input(input);
		process_farm_description(&input, farm);
		make_ants(farm);
	}
	wipe_input(&input_start);
	return (OK);
}
