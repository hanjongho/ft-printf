/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 23:44:37 by hanjongho         #+#    #+#             */
/*   Updated: 2021/01/21 00:15:28 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *args, ...)
{
	char		*tmp;
	t_pf_fmt	fmt;
	t_pf_len	len;
	va_list		ap;

	va_start(ap, args);
	tmp = (char *)args;
	fmt.spec_value = NULL;
	len.total_len = 0;
	parse_str(tmp, &fmt, &len, &ap);
	va_end(ap);
	return (len.total_len);
}

void			reset_fmt(t_pf_fmt *fmt)
{
	fmt->is_null = 0;
	fmt->is_left = 0;
	fmt->is_zero = 0;
	fmt->width = 0;
	fmt->is_prec = 0;
	fmt->prec = 0;
	fmt->left_prec = 0;
	fmt->is_value_negative = 0;
	fmt->value_len = 0;
	fmt->specifier = '\0';
	ft_strdel(&fmt->spec_value);
}
