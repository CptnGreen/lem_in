/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_and_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:22:22 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/18 21:23:35 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	putstr_and_count(char *str, t_frm *tmp)
{
	ft_putstr(str);
	tmp->ret += ft_strlen(str);
}
