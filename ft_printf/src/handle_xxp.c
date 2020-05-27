/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_xxp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:33:44 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/26 12:13:21 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_hash_xx(t_frm *tmp, char *s, char c)
{
	if (tmp->hash == 1)
	{
		if (s[0] != '0' || c == 'p')
			putstr_and_count((c == 'X') ? ("0X") : ("0x"), tmp);
	}
}

void	mod_width_xx(t_frm *tmp, char *s, char c)
{
	if (tmp->w > 0)
	{
		if (tmp->hash == 1)
		{
			if (s[0] != '0' || c == 'p')
				tmp->w -= 2;
		}
	}
}

void	handle_zero_xx(t_frm *tmp, int t)
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

void	handle_hash_and_zero_xx(t_frm *tmp, int t, char *s, char c)
{
	if (tmp->hash && tmp->zero)
	{
		if (t + 2 < tmp->w - 1 && tmp->precision > 0)
		{
			mod_width_xx(tmp, s, c);
			handle_zero_xx(tmp, t);
			handle_hash_xx(tmp, s, c);
		}
		else
		{
			mod_width_xx(tmp, s, c);
			handle_hash_xx(tmp, s, c);
			handle_zero_xx(tmp, t);
		}
	}
	else
	{
		if (tmp->hash)
			mod_width_xx(tmp, s, c);
		handle_zero_xx(tmp, t);
		handle_hash_xx(tmp, s, c);
	}
}

void	handle_xxp(t_frm *tmp, va_list argptr, char x, char c)
{
	int		t;
	char	*s;
	int		i;

	if (c == 'p')
	{
		tmp->hash = 1;
		tmp->size = 11;
	}
	s = get_s_xx(tmp, x, argptr);
	t = ft_strlen(s);
	handle_hash_and_zero_xx(tmp, t, s, c);
	print_string_ouxxp(tmp, s, t, c);
	i = 0;
	if (tmp->minus)
	{
		while (i++ < tmp->w - ((tmp->precision > t) ? (tmp->precision) : (t)))
			putchar_and_count(' ', tmp);
	}
	ft_strdel(&s);
}
