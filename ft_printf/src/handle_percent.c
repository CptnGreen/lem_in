/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 02:40:02 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/22 05:27:20 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_zero_percent(t_frm *tmp)
{
	int		i;

	i = 0;
	if (!(tmp->minus))
	{
		while (i++ < tmp->w - 1)
			putchar_and_count(((tmp->zero) ? ('0') : (' ')), tmp);
	}
}

void	handle_minus_percent(t_frm *tmp)
{
	int		i;

	i = 0;
	if (tmp->minus)
	{
		while (i++ < tmp->w - 1)
			putchar_and_count(' ', tmp);
	}
}

void	handle_percent(t_frm *tmp)
{
	handle_zero_percent(tmp);
	putchar_and_count('%', tmp);
	handle_minus_percent(tmp);
}
