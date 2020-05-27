/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:26:57 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/26 12:21:52 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#define STEPS_F 23
#define STEPS_D 52

char	*ft_dtoa(double value)
{
	int		i;
	char	*str;
	char	*tmp;

	str = ft_strnew(STEPS_D + 1);
	tmp = ft_itoa_unsigned_base((long long int)value, 10, 'X');
	ft_strncpy(str, tmp, (i = ft_strlen(tmp)));
	str[i++] = '.';
	while (i < STEPS_D)
	{
		value = 10 * (value - (double)((long long int)value));
		str[i] = (long long int)value + '0';
		i += 1;
	}
	ft_strdel(&tmp);
	return (str);
}
