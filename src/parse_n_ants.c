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
#define MISSING_ANTS "parse_n_ants(): Can't find number of ants - aborting.\n"
#define WRONG_ANTS "parse_n_ants(): Wrong ants' declaration - aborting.\n"

/*
** Called from process_farm_description()
**
** Treats as errors:
** - bad symbols in declaration
** - number of ants negative or zero
**
** On number of ants too big (for int) ft_atoi() returns 0
** so parse_n_ants() shoots error;
** on number too small ft_atoi() returns -1 so
** parse_n_ants() shoots error just the same.
*/

int			parse_n_ants(t_farm *farm, t_input_line **input)
{
	char			*line;
	int				i;

	while (*input)
	{
		line = ft_strdup((*input)->line);
		i = 0;
		while (line[i])
		{
			if (line[i] < '0' || line[i] > '9')
			{
				ft_putstr_fd(WRONG_ANTS, farm->log_fd);
				ft_strdel(&line);
				return (KO);
			}
			i += 1;
		}
		if ((farm->n_ants = ft_atoi(line)) > 0)
		{
			ft_putstr_fd("parse_n_ants(): Number of ants = ", farm->log_fd);
			ft_putnbr_fd(farm->n_ants, farm->log_fd);
			ft_putstr_fd("\n", farm->log_fd);
			ft_strdel(&line);
			(*input) = (*input)->next;
			return (OK);
		}
		ft_strdel(&line);
		ft_putstr_fd(NO_ANTS, farm->log_fd);
		return (KO);
	}
	ft_putstr_fd(MISSING_ANTS, farm->log_fd);
	return (KO);
}
