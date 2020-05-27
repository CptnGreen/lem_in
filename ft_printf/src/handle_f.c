/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:17:37 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/26 12:21:03 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_sgn_and_space_f(t_frm *tmp)
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

void	handle_zero_f(t_frm *tmp, int t)
{
	int		i;

	i = 0;
	if (!(tmp->minus))
	{
		if (tmp->zero && t < tmp->w)
			handle_sgn_and_space_f(tmp);
		while (i < tmp->w - t)
		{
			putchar_and_count(((tmp->zero) ? ('0') : (' ')), tmp);
			i += 1;
		}
		if (!(tmp->plus) && tmp->precision != 0)
			handle_sgn_and_space_f(tmp);
	}
}

void	print_string_f(t_frm *tmp, char *s)
{
	int		i;
	int		j;

	handle_sgn_and_space_f(tmp);
	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (tmp->precision != 0 || tmp->hash)
				putchar_and_count(s[i], tmp);
			i += 1;
			break ;
		}
		putchar_and_count(s[i], tmp);
		i += 1;
	}
	j = 0;
	while (s[i] && j < tmp->precision)
	{
		putchar_and_count(s[i], tmp);
		i += 1;
		j += 1;
	}
}

int		get_float_len(t_frm *tmp, char *s)
{
	int		t;

	t = 0;
	while (1)
	{
		t += 1;
		if (s[t] == '.')
		{
			t += 1;
			break ;
		}
	}
	if (tmp->precision == 0)
		t -= 1;
	else
		t += tmp->precision;
	if (tmp->plus || tmp->space || tmp->sgn == '-')
		t += 1;
	return (t);
}

void	handle_f(t_frm *tmp, va_list argptr)
{
	char	*s;
	int		t;

	if (tmp->precision < 0)
		tmp->precision = 6;
	s = get_s_f(tmp, argptr);
	t = get_float_len(tmp, s);
	handle_zero_f(tmp, t);
	print_string_f(tmp, s);
	if (tmp->minus)
	{
		while ((int)(tmp->ret) < tmp->w)
			putchar_and_count(' ', tmp);
	}
	ft_strdel(&s);
}
