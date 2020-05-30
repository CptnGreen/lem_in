/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipe_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:07 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:08 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	wipe_paths(t_path **path)
{
	t_path	*p;
	t_path	*prev_p;

	p = *path;
	while (p)
	{
		prev_p = p;
		p = p->next;
		free(prev_p);
		prev_p = NULL;
	}
}
