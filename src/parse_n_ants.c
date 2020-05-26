/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_n_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:12 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:13 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define NO_ANTS "parse_n_ants(): Number of ants <= 0 (or too many). Aborting.\n"
#define ANTS_MISSING "parse_n_ants(): Can't find number of ants - aborting.\n"

/*
** Called from process farm_description()
*/

int			parse_n_ants(t_farm *farm, t_input_line **input_passed)
{
	t_input_line	*input;
	char			*line;

	input = *input_passed;
	while (input)
	{
		line = ft_strdup(input->line);
		if (line[0] == '#')
		{
			ft_strdel(&line);
			input = input->next;
			continue ;
		}
		if ((farm->n_ants = ft_atoi(line)) > 0)
		{
			ft_putstr_fd("parse_n_ants(): Number of ants = ", farm->log_fd);
			ft_putnbr_fd(farm->n_ants, farm->log_fd);
			ft_putstr_fd("\n", farm->log_fd);
			ft_strdel(&line);
			*input_passed = input->next;
			return (OK);
		}
		ft_strdel(&line);
		ft_putstr_fd(NO_ANTS, farm->log_fd);
		return (KO);
	}
	ft_putstr_fd(ANTS_MISSING, farm->log_fd);
	return (KO);
}
