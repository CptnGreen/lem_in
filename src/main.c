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
#include "libft.h"
#include "libftprintf.h"

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
	int				res;
	int				n_min_turns;
	int				n_turns;
	int				n_max_paths;
	char			**m_res;
	t_input_line	**input_start;

	if (init_farm(&farm) && \
		get_input(&farm, FD, &input))
	{
		input_start = &input;
		print_input(input);
		process_farm_description(&input, &farm);
	}
	n_min_turns = 1000000;
	n_max_paths = 1;
	res = -1;
	make_ants(&farm);
	while (res != NO_MORE_PATHS_FOUND)
	{
		res = find_next_path(&farm);
		sort_paths(&farm);
		n_turns = redistribute_ants(&farm);
		print_paths(farm.paths);
		ft_printf("n_turns: %d\n", n_turns);
		if (n_turns <= n_min_turns)
		{
			n_min_turns = n_turns;
			wipe_mstr(m_res);
			m_res = mstr_dup((char const **)farm.adj_matrix, farm.n_rooms, farm.n_rooms);
			continue ;
		}
		wipe_mstr(farm.adj_matrix);
		farm.adj_matrix = m_res;
		sort_paths(&farm);
		n_turns = redistribute_ants(&farm);
		break ;
	}
	lem_in(&farm);
	wipe_input(input_start);
	wipe_farm(&farm);
	return (0);
}
