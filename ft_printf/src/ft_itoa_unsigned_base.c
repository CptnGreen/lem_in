/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 23:22:44 by fcatina           #+#    #+#             */
/*   Updated: 2020/02/22 07:24:14 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa_unsigned_base(unsigned long long value, int base, char c)
{
	unsigned long long	size;
	unsigned long long	tmp;
	char				*tab;
	char				*str;

	tmp = value;
	size = 0;
	if (c == 'x')
		tab = "0123456789abcdef";
	else
		tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	while (tmp /= base)
		size++;
	size = size + 1;
	str = (char*)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	while (size > 0)
	{
		size--;
		str[size] = tab[value % base];
		value /= base;
	}
	return (str);
}
