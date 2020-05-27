/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:15:57 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/26 12:13:22 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_zero_o(t_frm *tmp, int t)
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

void	handle_hash_o(t_frm *tmp, char *s, int t)
{
	if (tmp->hash == 1 && s[0] != '0' && t + 1 > tmp->precision)
		putchar_and_count('0', tmp);
}

void	mod_w_o(t_frm *tmp, char *s, int t)
{
	if (tmp->w > 0)
	{
		if (tmp->hash == 1 && s[0] != '0' && !(t + 1 <= tmp->precision))
			tmp->w -= 1;
	}
}

void	mod_w_and_handle_hash_o(t_frm *tmp, int t, char *s)
{
	if (tmp->hash && tmp->zero)
	{
		if (t + 1 < tmp->w - 1 && tmp->precision > 0)
		{
			mod_w_o(tmp, s, t);
			handle_zero_o(tmp, t);
			handle_hash_o(tmp, s, t);
		}
		else
		{
			mod_w_o(tmp, s, t);
			handle_hash_o(tmp, s, t);
			handle_zero_o(tmp, t);
		}
	}
	else
	{
		mod_w_o(tmp, s, t);
		handle_zero_o(tmp, t);
		handle_hash_o(tmp, s, t);
	}
}

void	handle_o(t_frm *tmp, va_list argptr, char c)
{
	char	*s;
	int		t;
	int		i;

	s = get_s_o(tmp, argptr);
	t = ft_strlen(s);
	mod_w_and_handle_hash_o(tmp, t, s);
	print_string_ouxxp(tmp, s, t, c);
	i = 0;
	if (tmp->minus)
	{
		while (i++ < tmp->w - ((tmp->precision > t) ? (tmp->precision) : (t)))
			putchar_and_count(' ', tmp);
	}
	ft_strdel(&s);
}
