/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:52:47 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/26 05:11:58 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_minus_c(t_frm *tmp, char *c, int is_minus, char *s)
{
	int		i;

	if (tmp->minus == is_minus && \
		(tmp->plus || \
		s[0] != '0' || \
		(s[0] == '0' && tmp->w > 0 && tmp->precision > 0)))
	{
		i = 0;
		while (i < tmp->w && tmp->w - i > \
			((*c == '0') ? (tmp->precision) : (0)))
		{
			putchar_and_count(*c, tmp);
			i += 1;
		}
	}
}

void	handle_c(t_frm *tmp, va_list argptr, int *l)
{
	(*l) = va_arg(argptr, int);
	tmp->w = tmp->w - 1;
	handle_minus_c(tmp, " ", 0, "1");
	putchar_and_count((char)*l, tmp);
	handle_minus_c(tmp, " ", 1, "1");
}
