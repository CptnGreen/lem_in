/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:03:00 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/26 11:41:50 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_s_s(t_frm *tmp, va_list argptr)
{
	char	*s;

	s = va_arg(argptr, char *);
	if (s == NULL)
	{
		s = ft_strdup("(null)");
		tmp->is_null = 1;
	}
	return (s);
}

void	handle_nonzero_width_s(t_frm *tmp, int t, char *s, int *i)
{
	int		j;
	int		n;

	j = 0;
	if (!(tmp->minus))
	{
		j = ((t < tmp->precision || tmp->precision < 0) ? \
			(tmp->w - t) : (tmp->w - tmp->precision));
		while (j-- > 0)
			putchar_and_count(' ', tmp);
	}
	n = ((tmp->precision > 0) ? (tmp->precision) : (t));
	while ((*i) < n && s[(*i)])
		putchar_and_count(s[(*i)++], tmp);
}

void	handle_zero_width_s(t_frm *tmp, char *s, int *i)
{
	if (tmp->precision > 0)
	{
		while ((*i) < tmp->precision && s[(*i)])
			putchar_and_count(s[(*i)++], tmp);
	}
	else if (tmp->precision < 0)
		putstr_and_count(s, tmp);
}

void	print_string_s(t_frm *tmp, char *s, int t)
{
	int		i;

	i = 0;
	if (tmp->precision != 0)
	{
		if (s[0] != '0' || tmp->precision >= 0)
		{
			if (tmp->w != 0)
				handle_nonzero_width_s(tmp, t, s, &i);
			else if (tmp->w == 0)
				handle_zero_width_s(tmp, s, &i);
		}
		else if (tmp->w != 0 && tmp->precision >= 0)
			putchar_and_count(' ', tmp);
	}
	else if (!(tmp->minus) && tmp->w > 0)
	{
		while (i++ < tmp->w)
			putchar_and_count(' ', tmp);
	}
}

void	handle_s(t_frm *tmp, va_list argptr)
{
	char	*s;
	int		t;
	int		i;
	int		j;

	s = get_s_s(tmp, argptr);
	t = ft_strlen(s);
	print_string_s(tmp, s, t);
	i = 0;
	j = 0;
	if (tmp->minus)
	{
		if (tmp->w > 0)
		{
			j = ((t < tmp->precision || tmp->precision < 0) ? \
				(tmp->w - t) : (tmp->w - tmp->precision));
			while (i++ < j)
				putchar_and_count(' ', tmp);
		}
	}
	if (tmp->is_null)
		ft_strdel(&s);
}
