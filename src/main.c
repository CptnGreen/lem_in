/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:07 by slisandr          #+#    #+#             */
/*   Updated: 2020/06/05 05:44:20 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define SUCCESS 0
#define FAILURE 1

/*
** The solution consists of 3 steps:
** 1. read, store, print, parse and check input
** 2. calculate best paths and assotiate ants with them
** 3. print ants' movements line by line
*/

int		main(void)
{
	t_farm		farm;

	if (process_input(&farm) && \
		set_the_stage(&farm) && \
		lem_in(&farm))
	{
		wipe_farm(&farm);
		exit(SUCCESS);
	}
	wipe_farm(&farm);
	ft_putstr("ERROR\n");
	exit(FAILURE);
}
