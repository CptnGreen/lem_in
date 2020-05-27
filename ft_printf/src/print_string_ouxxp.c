/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_ouxxp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:16:34 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/26 06:16:59 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_string_ouxxp(t_frm *tmp, char *s, int t, char c)
{
	int		i;

	i = 0;
	if (s[0] != '0' || \
		tmp->precision != 0 || \
		(tmp->hash && ((c == 'o' && tmp->precision >= 0) || \
				((c == 'x' || c == 'X') && (tmp->precision >= 1)))))
	{
		{
			while (i++ < tmp->precision - t)
				putchar_and_count('0', tmp);
			putstr_and_count(s, tmp);
		}
	}
	else if (tmp->w > 0 && tmp->precision >= 0)
		putchar_and_count(' ', tmp);
}
