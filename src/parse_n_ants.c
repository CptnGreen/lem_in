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

#define ER_A1 "parse_n_ants(): Number of ants <= 0 (or too many).\n"
#define ER_A2 "check_first_line(): First line is empty.\n"
#define ER_A3 "check_first_line(): Non-digits in the first line.\n"

/*
** The very first line of input *must* contain positive integer;
** Anything else (including comments) triggers error.
*/

int		check_first_line(t_farm *farm, char *line)
{
	int		i;

	i = 0;
	if (line[i])
	{
		while (line[i])
		{
			if (line[i] < '0' || line[i] > '9')
			{
				ft_putstr_fd(ER_A3, farm->log_fd);
				ft_strdel(&line);
				return (KO);
			}
			i += 1;
		}
		return (OK);
	}
	ft_putstr_fd(ER_A2, farm->log_fd);
	return (KO);
}

/*
** Called from main() -> process_input() -> parse_input()
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

int		parse_n_ants(t_farm *farm, t_input_line **input)
{
	char	*line;

	line = ft_strdup((*input)->line);
	if (check_first_line(farm, line) == KO)
		return (KO);
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
	ft_putstr_fd(ER_A1, farm->log_fd);
	return (KO);
}
