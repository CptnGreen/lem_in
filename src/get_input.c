/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:07:49 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:07:50 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		read_input(int fd, t_input_line **input_lst)
{
	t_input_line	*prev;
	t_input_line	*cur;
	char			*line;
	int				is_first;

	line = NULL;
	cur = NULL;
	is_first = 1;
	while (get_next_line(fd, &line) > 0)
	{
		prev = cur;
		if (!(cur = (t_input_line *)ft_memalloc(sizeof(t_input_line))))
		{
			ft_strdel(&line);
			return (KO);
		}
		if (is_first)
			*input_lst = cur;
		is_first = ((is_first) ? (0) : (is_first));
		if (prev)
			prev->next = cur;
		cur->line = ft_strdup(line);
		ft_strdel(&line);
	}
	return (OK);
}

/*
** Called in process_input()
**
** TODO: Fix memory leaks!
*/

int		get_input(t_farm *farm, int fd, t_input_line **input_lst)
{
	if (!(*input_lst))
	{
		if (read_input(fd, input_lst) == KO)
			return (KO);
		ft_putstr_fd("get_input(): Input parsed to list.\n", farm->log_fd);
		return (OK);
	}
	ft_putstr_fd("get_input(): Input empty; Aborting.\n", farm->log_fd);
	return (KO);
}
