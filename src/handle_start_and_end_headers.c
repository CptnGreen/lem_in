/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_start_and_end_headers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:07:52 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:07:52 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			handle_start_header(t_farm *farm, char **line)
{
	if (ft_strequ(*line, "##start"))
	{
		ft_putstr_fd("handle_start_header(): Found start declaration line\n", farm->log_fd);
		ft_strdel(line);
		if (farm->start_counter == 0)
		{
			farm->start_counter += 1;
			return (FOUND_START);
		}
		else
		{
			ft_putstr_fd("handle_start_header(): Too many start headers. Aborting.\n", farm->log_fd);
			return (HEADERS_TOO_MANY);
		}
	}
	return (COMMENT_FOUND);
}

int			handle_end_header(t_farm *farm, char **line)
{
	if (ft_strequ(*line, "##end"))
	{
		ft_putstr_fd("handle_end_header(): Found end declaration line\n", farm->log_fd);
		ft_strdel(line);
		if (farm->end_counter == 0)
		{
			farm->end_counter += 1;
			return (FOUND_END);
		}
		else
		{
			ft_putstr_fd("handle_end_header(): Too many end headers. Aborting.\n", farm->log_fd);
			return (HEADERS_TOO_MANY);
		}
	}
	return (COMMENT_FOUND);
}

/*
** Called from parse_rooms()
*/

int			handle_start_and_end_headers(t_farm *farm, char **line)
{
	int		res;

	if ((res = handle_start_header(farm, line)) != COMMENT_FOUND || \
		(res = handle_end_header(farm, line)) != COMMENT_FOUND)
		return (res);
	return (COMMENT_FOUND);
}
