/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:27 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:28 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		print_links(t_link *links)
{
	t_link		*link;
	int			i;

	if (links)
	{
		i = 0;
		link = links;
		while (link)
		{
			printf("%s-%s\n", link->src, link->dst);
			link = link->next;
			i += 1;
		}
		return (OK);
	}
	perror("lem_in: Couldn't print links 'cause passed argument is NULL.\n");
	return (KO);
}
