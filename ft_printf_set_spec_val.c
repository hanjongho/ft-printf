/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set_spec_val.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 23:45:57 by hanjongho         #+#    #+#             */
/*   Updated: 2021/01/20 23:40:12 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		check_null(t_pf_fmt *fmt)
{
	if (fmt->specifier == 'p')
		fmt->is_null = !ft_strcmp(fmt->spec_value, "0x0") ? 1 : 0;
	if (fmt->specifier == 'c')
		fmt->is_null = !ft_strcmp(fmt->spec_value, "\0") ? 1 : 0;
	if (ft_strchr(fmt->spec_value, '-'))
		fmt->is_value_negative = 1;
}

static char		*fmt_check_hex(char *hex, char spec)
{
	int			hex_len;
	int			zero_idx;
	char		*ret;

	if (!ft_strcmp(hex, "0"))
		return (spec == 'p' ? ft_strdup("0x0") : hex);
	hex_len = ft_strlen(hex);
	zero_idx = ft_count_begin_char(hex, '0');
	if (spec == 'x' || spec == 'X')
		ret = ft_strsub(hex, zero_idx, hex_len);
	else if (spec == 'p')
		ret = zero_idx == hex_len ?
		ft_strdup("0x0") : ft_strsubjoin("0x", hex, zero_idx);
	ft_strdel(&hex);
	hex_len = ft_strlen(ret);
	if (spec == 'x' || spec == 'p')
		while (hex_len >= 0)
		{
			ret[hex_len] = ft_tolower(ret[hex_len]);
			hex_len--;
		}
	return (ret);
}

void			set_spec_val(t_pf_fmt *fmt, va_list *ap)
{
	char		*tmp;

	if (fmt->specifier == 'c')
		fmt->spec_value = ft_atos((unsigned char)va_arg(*ap, int));
	else if (fmt->specifier == 's')
	{
		tmp = ft_strdup(va_arg(*ap, char *));
		fmt->spec_value = tmp == NULL ? ft_strdup("(null)") : tmp;
	}
	else if (fmt->specifier == 'p')
		fmt->spec_value = fmt_check_hex(ft_itoa_base_unsigned(
			va_arg(*ap, unsigned long long int), 16), fmt->specifier);
	else if (fmt->specifier == 'd' || fmt->specifier == 'i')
		fmt->spec_value = ft_itoa(va_arg(*ap, int));
	else if (fmt->specifier == 'u')
		fmt->spec_value = ft_itoa_unsigned(va_arg(*ap, unsigned int));
	else if (fmt->specifier == 'x' || fmt->specifier == 'X')
		fmt->spec_value = fmt_check_hex(ft_itoa_base_unsigned(
			va_arg(*ap, unsigned int), 16), fmt->specifier);
	else if (fmt->specifier == '%')
		fmt->spec_value = ft_atos('%');
	else
		return ;
	check_null(fmt);
	fmt->value_len = ft_strlen(fmt->spec_value);
}
