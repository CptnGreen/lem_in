/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_s_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 07:13:13 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/26 11:17:37 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_s_o(t_frm *tmp, va_list argptr)
{
	char				*s;
	unsigned long long	value;

	if (tmp->size == 6)
		value = (unsigned short)va_arg(argptr, unsigned long long);
	else if (tmp->size == 66)
		value = (unsigned char)va_arg(argptr, unsigned long long);
	else if (tmp->size == 1)
		value = (unsigned long)va_arg(argptr, unsigned long long);
	else if (tmp->size == 11)
		value = (unsigned long long)va_arg(argptr, unsigned long long);
	else
		value = (unsigned int)va_arg(argptr, unsigned long long);
	s = ft_itoa_unsigned_base(value, 8, 'X');
	return (s);
}
