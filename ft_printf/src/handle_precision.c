/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 23:02:56 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/18 23:10:20 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_precision(t_frm *tmp, char *s)
{
	int		i;

	if ((s[0] != '0') || (s[0] == '0' && tmp->w > 0 && tmp->precision > 0))
	{
		i = 0;
		while (i < tmp->precision)
		{
			putchar_and_count('0', tmp);
			i += 1;
		}
	}
}
