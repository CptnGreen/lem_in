/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:02:30 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/26 12:22:13 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "libft.h"

/*
** nb - how many spaces or zeroes, hash - #,
** w (width) - between 1 and 9, precision - .#,
** size: ll = 11, l = 1, hh = 66, h = 6, L = 10, else == 0.
*/

typedef	struct		s_form
{
	char	sgn;
	char	format;
	char	*string;
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		hash;
	int		w;
	int		precision;
	int		size;
	char	*head;
	int		l_head;
	char	*tail;
	int		l_tail;
	int		sgn_is_printed;
	int		is_null;
	size_t	ret;
}					t_frm;

int					ft_printf(const char *format, ...);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
char				*ft_itoa_base(int value, int base);
char				*x_ft_itoa_base(int value, int base);
char				*ft_itoa_unsigned_base(unsigned long long value, \
												int base, char c);
char				*ft_dtoa(double value);
char				*ft_ldtoa(long double value);
void				fix_s(char *s, char c, int is_minus, int n);
void				handle_c(t_frm *tmp, va_list argptr, int *l);
void				handle_s(t_frm *tmp, va_list argptr);
void				handle_xxp(t_frm *tmp, va_list argptr, char x, char c);
void				handle_o(t_frm *tmp, va_list argptr, char c);
void				handle_u(t_frm *tmp, va_list argptr, char c);
void				handle_id(t_frm *tmp, va_list argptr);
void				handle_f(t_frm *tmp, va_list argptr);
void				putchar_and_count(char c, t_frm *tmp);
void				putstr_and_count(char *str, t_frm *tmp);
t_frm				process_flags(const char *format, int i);
void				handle_percent(t_frm *tmp);
void				reset_struct(t_frm *tmp);
void				handle_precision(t_frm *tmp, char *s);
void				print_string_ouxxp(t_frm *tmp, char *s, int t, char c);
char				*get_s_f(t_frm *tmp, va_list argptr);
char				*get_s_xx(t_frm *tmp, char x, va_list argptr);
char				*get_s_o(t_frm *tmp, va_list argptr);

#endif
