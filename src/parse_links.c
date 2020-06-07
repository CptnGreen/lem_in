/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:10 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:11 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define ER_L1 "handle_hash_in_links(): Start/end directive found in links.\n"
#define ER_L3 "parse_next_link(): Empty line.\n"
#define ER_L4 "parse_links(): No links found.\n"
#define ER_L5 "parse_links(): No start or end room in links.\n"

#define ME_L1 "handle_hash_in_links(): End of input. Last line is a comment.\n"
#define ME_L2 "parse_next_link(): Reached end of input.\n"

#define END_OF_INPUT 5

/*
** Skips comments and reports on end of input.
**
** Start/end directive in links is treated as error.
*/

int		handle_hash_in_links(t_farm *farm, t_input_line **input)
{
	char	*l;

	l = (*input)->line;
	while (l[0] == '#')
	{
		if (ft_strequ(l, "##start") || ft_strequ(l, "##end"))
		{
			ft_putstr_fd(ER_L1, farm->log_fd);
			return (KO);
		}
		*input = (*input)->next;
		if (!(*input))
		{
			ft_putstr_fd(ME_L1, farm->log_fd);
			return (END_OF_INPUT);
		}
	}
	return (OK);
}

/*
** Checks if link consists of exactly 2 parts
*/

int		parse_next_link(t_farm *farm, t_input_line **input)
{
	char		**split;
	int			res;
	char		*l;

	l = (*input)->line;
	if (l[0] == '\0')
	{
		ft_putstr_fd(ER_L3, farm->log_fd);
		return (KO);
	}
	if ((res = handle_hash_in_links(farm, input)) != OK)
		return (res);
	split = ft_strsplit(l, '-');
	if (!split[0] || !split[1] || split[2] || \
		check_link(farm, split[0], split[1]) == KO)
	{
		wipe_mstr(split);
		return (KO);
	}
	wipe_mstr(split);
	return (OK);
}

/*
** This function is called in [process_input() -> ] parse_input()
** after parse_n_ants() and parse_rooms().
*/

int		parse_links(t_farm *farm, t_input_line **input)
{
	int		res;

	if (*input)
	{
		farm->start_counter = 0;
		farm->end_counter = 0;
		while (*input)
		{
			if ((res = parse_next_link(farm, input)) == END_OF_INPUT)
				break ;
			else if (res == KO)
				return (KO);
			*input = (*input)->next;
		}
		if (farm->start_counter > 0 && farm->end_counter > 0)
		{
			ft_putstr_fd(ME_L2, farm->log_fd);
			return (OK);
		}
		if (res != END_OF_INPUT)
			ft_putstr_fd(ER_L5, farm->log_fd);
		return (KO);
	}
	ft_putstr_fd(ER_L4, farm->log_fd);
	return (KO);
}
