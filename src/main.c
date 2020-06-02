/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:07 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:08 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	t_farm		farm;

	if (process_input(&farm) &&	\
		set_the_stage(&farm) &&	\
		lem_in(&farm))
	{
		wipe_farm(&farm);
		return (0);
	}
	wipe_farm(&farm);
	perror("ERROR\n");
	return (1);
}
