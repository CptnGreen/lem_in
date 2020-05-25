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

/*
** This function is called in main()
*/

int		get_input(t_farm *farm, int fd, t_input_line **input_lst)
{
	t_input_line	*prev;
	t_input_line	*cur;
	char			*line;
	int				is_first;

	cur = NULL;
	line = NULL;
	is_first = 1;
	while (get_next_line(fd, &line) > 0)
	{
		prev = cur;
		if (!(cur = (t_input_line *)ft_memalloc(sizeof(t_input_line))))
			return (KO);
		if (is_first)
		{
			*input_lst = cur;
			is_first = 0;
		}
		if (prev)
			prev->next = cur;
		cur->line = ft_strdup(line);
		ft_strdel(&line);
		cur->next = NULL;
	}
	if (cur)
	{
		ft_putstr_fd("get_input(): Input parsed to list.\n", farm->log_fd);
		return (OK);
	}
	ft_putstr_fd("get_input(): Input empty; Aborting.\n", farm->log_fd);
	return (KO);
}
