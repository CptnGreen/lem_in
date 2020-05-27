/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:28:49 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/26 12:22:13 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#define STEPS_LD 80

char	*ft_ldtoa(long double value)
{
	int		i;
	char	*str;
	char	*tmp;

	str = ft_strnew(STEPS_LD + 1);
	tmp = ft_itoa_unsigned_base((long long int)value, 10, 'X');
	ft_strncpy(str, tmp, (i = ft_strlen(tmp)));
	str[i++] = '.';
	while (i < STEPS_LD)
	{
		value = 10 * (value - (long double)((long long int)value));
		str[i] = (long long int)value + '0';
		i += 1;
	}
	ft_strdel(&tmp);
	return (str);
}
