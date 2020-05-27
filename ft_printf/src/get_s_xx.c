/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_s_xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:41:57 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/26 06:56:23 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_s_xx(t_frm *tmp, char x, va_list argptr)
{
	char				*s;
	unsigned long long	value;

	s = NULL;
	value = ((tmp->size == 0) ? \
			(va_arg(argptr, unsigned int)) : \
			(va_arg(argptr, unsigned long long)));
	if (tmp->size == 6)
		fix_s((s = ft_itoa_unsigned_base((short int)value, 16, x)), \
			((x == 'X') ? ('F') : ('f')), 12, 11);
	else if (tmp->size == 66)
		fix_s((s = ft_itoa_unsigned_base((signed char)value, 16, x)), \
			((x == 'X') ? ('F') : ('f')), 13, 13);
	else
		s = ft_itoa_unsigned_base(value, 16, x);
	return (s);
}
