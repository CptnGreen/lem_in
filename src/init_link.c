/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:02 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:03 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link		*init_link(t_farm *farm, char const *src, char const *dst)
{
	t_link	*link;

	link = NULL;
	if ((link = (t_link *)ft_memalloc(sizeof(t_link))))
	{
		link->src = ((src) ? (ft_strdup(src)) : (NULL));
		link->dst = ((dst) ? (ft_strdup(dst)) : (NULL));
		link->next = NULL;
	}
	else
		ft_putstr_fd(\
			"init_link(): Failed to allocate memory for a new link.\n", \
			farm->log_fd);
	return (link);
}
