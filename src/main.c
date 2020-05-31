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

int			make_ants(t_farm *farm)
{
	int				i;
	t_ant			*a;
	t_path			*p;

	i = 0;
	while (i < farm->n_ants)
	{
		init_and_append_ant(farm, i + 1);
		i += 1;
	}
	a = farm->ants;
	while (a)
	{
		p = farm->paths;
		while (p->next && \
			   p->n_ants_inside + p->gateway_room->d >=	\
			   p->next->n_ants_inside + p->next->gateway_room->d)
			p = p->next;
		enqueue_ant(&(p->ants), a);
		p->n_ants_inside += 1;
		enqueue_ant(&(farm->start_room->ants), a);
		a = a->next;
	}
	return (OK);
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
		if (process_farm_description(&input, &farm))
		{
			while (find_path(&farm) != NO_MORE_PATHS_FOUND)
				;
			sort_paths(&farm);
			make_ants(&farm);
			if (lem_in(&farm))
			{
				wipe_input(&input_start);
				wipe_farm(&farm);
				return (0);
			}
		}
	}
	ft_printf("ERROR\n");
	return (1);
}
