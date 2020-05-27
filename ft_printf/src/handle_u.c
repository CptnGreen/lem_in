/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:03:37 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/26 12:13:22 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_s_u(t_frm *tmp, va_list argptr)
{
	char				*s;
	unsigned long long	value;

	if (tmp->size == 6)
		value = (unsigned short)va_arg(argptr, unsigned long long);
	else if (tmp->size == 66)
		value = (unsigned char)va_arg(argptr, unsigned long long);
	else if (tmp->size == 11 || tmp->size == 1)
		value = va_arg(argptr, unsigned long long);
	else
		value = (unsigned int)va_arg(argptr, unsigned long long);
	s = ft_itoa_unsigned_base(value, 10, 'X');
	return (s);
}

void	handle_zero_u(t_frm *tmp, int t)
{
	int		i;

	i = 0;
	if (tmp->minus == 0)
	{
		while (i < tmp->w - ((tmp->precision > t) ? (tmp->precision) : (t)))
		{
			putchar_and_count(((tmp->zero && tmp->precision < 0) ? \
										('0') : (' ')), tmp);
			i += 1;
		}
	}
}

void	handle_minus_u(t_frm *tmp, int t)
{
	int		i;

	i = 0;
	if (tmp->minus)
	{
		while (i < tmp->w - ((tmp->precision > t) ? (tmp->precision) : (t)))
		{
			putchar_and_count(' ', tmp);
			i += 1;
		}
	}
}

void	handle_u(t_frm *tmp, va_list argptr, char c)
{
	char	*s;
	int		t;

	s = get_s_u(tmp, argptr);
	t = ft_strlen(s);
	handle_zero_u(tmp, t);
	print_string_ouxxp(tmp, s, t, c);
	handle_minus_u(tmp, t);
	ft_strdel(&s);
}
