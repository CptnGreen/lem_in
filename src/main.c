/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:07 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:08 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	wipe_input(t_input_line **input_passed)
{
	t_input_line	*input;
	t_input_line	*prev;

	if (*input_passed)
	{
		input = *input_passed;
		while (input)
		{
			prev = input;
			input = input->next;
			ft_strdel(&(prev->line));
			free(prev);
			prev = NULL;
		}
		input_passed = NULL;
	}
}

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

int		main(void)
{
	t_farm			farm;
	t_input_line	*input;
	t_input_line	*input_start;

	if (init_farm(&farm) && \
		get_input(&farm, FD, &input))
	{
		print_input(input);
		input_start = input;
		if (process_farm_description(&input, &farm) && \
			lem_in(&farm))
		{
			wipe_input(&input_start);
			wipe_farm(&farm);
			return (0);
		}
	}
	printf("ERROR\n");
	return (1);
}
