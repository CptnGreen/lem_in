/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:13:59 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/26 11:03:38 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	reset_struct(t_frm *tmp)
{
	tmp->sgn_is_printed = 0;
	tmp->is_null = 0;
	tmp->size = 0;
	tmp->plus = 0;
	tmp->sgn = '\0';
	tmp->string = NULL;
	tmp->minus = 0;
	tmp->space = 0;
	tmp->zero = 0;
	tmp->w = 0;
	tmp->hash = 0;
	tmp->format = 0;
	tmp->precision = -1;
	tmp->head = NULL;
	tmp->l_head = 0;
	tmp->tail = NULL;
	tmp->l_tail = 0;
}
