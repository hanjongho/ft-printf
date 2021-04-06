/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 23:44:42 by hanjongho         #+#    #+#             */
/*   Updated: 2021/01/20 23:17:26 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct	s_fmt
{
	size_t		is_null;
	size_t		is_left;
	size_t		is_zero;
	size_t		width;
	size_t		is_prec;
	size_t		prec;
	size_t		left_prec;
	size_t		is_value_negative;
	size_t		value_len;
	char		specifier;
	char		*spec_value;
}				t_pf_fmt;

typedef struct	s_length
{
	size_t		total_len;
}				t_pf_len;

int				ft_printf(const char *args, ...);
int				parse_numeric(char *str, size_t *fmt);
int				parse_fmt(char *str, t_pf_fmt *fmt, va_list *ap);
void			reset_fmt(t_pf_fmt *fmt);
void			parse_str(
				char *str, t_pf_fmt *fmt, t_pf_len *len, va_list *ap);
void			set_spec_val(t_pf_fmt *fmt, va_list *ap);
void			fmt_exception(t_pf_fmt *fmt, t_pf_len *len);

#endif
