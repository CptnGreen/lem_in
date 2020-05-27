/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_id_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:28:15 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/26 12:13:22 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_s_and_mod_w_id(t_frm *tmp, va_list argptr)
{
	char			*s;
	int long long	l;

	l = ((tmp->size == 0) ? \
		(va_arg(argptr, int)) : (va_arg(argptr, long long int)));
	if (tmp->size == 6 || tmp->size == 66)
		l = ((tmp->size == 66) ? ((char)l) : ((short)l));
	else if (tmp->size == 1 || tmp->size == 11 || tmp->size == 0)
		l = ((tmp->size == 11) ? ((long long int)l) : ((long int)l));
	if (l < 0)
	{
		tmp->sgn = '-';
		l *= -1;
		tmp->w -= 1;
	}
	else if (tmp->plus || tmp->space)
		tmp->w -= 1;
	s = ft_itoa_unsigned_base(l, 10, 'X');
	return (s);
}

void	handle_sgn_and_space_id(t_frm *tmp)
{
	if (tmp->sgn_is_printed == 0)
	{
		if (tmp->sgn == '-')
		{
			putchar_and_count('-', tmp);
			tmp->sgn_is_printed = 1;
		}
		else if (tmp->plus)
		{
			putchar_and_count('+', tmp);
			tmp->sgn_is_printed = 1;
		}
		else if (tmp->space)
		{
			putchar_and_count(' ', tmp);
			tmp->sgn_is_printed = 1;
		}
	}
}

void	handle_zero_id(t_frm *tmp, int t)
{
	int		i;

	i = 0;
	if (!(tmp->minus))
	{
		if (tmp->zero && tmp->precision <= 0 && t + 1 < tmp->w + 1)
			handle_sgn_and_space_id(tmp);
		while (i < tmp->w - ((tmp->precision > t) ? (tmp->precision) : (t)))
		{
			putchar_and_count(\
				((tmp->zero && tmp->precision < 0) ? \
									('0') : (' ')), tmp);
			i += 1;
		}
		if (!(tmp->plus) && tmp->precision != 0)
			handle_sgn_and_space_id(tmp);
	}
}

void	print_string_id(t_frm *tmp, char *s, int t)
{
	int		i;

	i = 0;
	if (s[0] != '0' || tmp->precision != 0)
	{
		handle_sgn_and_space_id(tmp);
		while (i++ < tmp->precision - t)
			putchar_and_count('0', tmp);
		putstr_and_count(s, tmp);
	}
	else if (tmp->w > 0 && tmp->precision >= 0)
	{
		if (tmp->minus)
			handle_sgn_and_space_id(tmp);
		if (!(tmp->plus || tmp->precision == 0))
			handle_sgn_and_space_id(tmp);
		putchar_and_count(' ', tmp);
		handle_sgn_and_space_id(tmp);
	}
	handle_sgn_and_space_id(tmp);
}

void	handle_id(t_frm *tmp, va_list argptr)
{
	char	*s;
	int		t;
	int		i;

	s = get_s_and_mod_w_id(tmp, argptr);
	t = ft_strlen(s);
	handle_zero_id(tmp, t);
	print_string_id(tmp, s, t);
	i = 0;
	if (tmp->minus)
	{
		while (i++ < tmp->w - ((tmp->precision > t) ? (tmp->precision) : (t)))
			putchar_and_count(' ', tmp);
	}
	ft_strdel(&s);
}
