/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipe_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-...>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 03:08:07 by slisandr          #+#    #+#             */
/*   Updated: 2020/05/25 03:08:08 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	wipe_input(t_input_line **input_passed)
{
	t_input_line	*input;
	t_input_line	*prev;

	if (*input_passed)
	{
		input = *input_passed;
		while (input)
		{
			prev = input;
			input = input->next;
			ft_strdel(&(prev->line));
			free(prev);
			prev = NULL;
		}
		input_passed = NULL;
	}
}
