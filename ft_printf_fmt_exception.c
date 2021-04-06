/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fmt_exception.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 23:45:04 by hanjongho         #+#    #+#             */
/*   Updated: 2021/01/24 01:47:33 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	re_len(t_pf_fmt *fmt, int c, size_t b_size)
{
	size_t		len;

	if (c == '0' && fmt->prec)
		len = fmt->is_value_negative ?
		b_size - (fmt->value_len - 2) : b_size - fmt->value_len;
	else
		len = fmt->is_value_negative ?
		b_size - (fmt->value_len - 1) : b_size - fmt->value_len;
	return (len);
}

static char		*fmt_padding(t_pf_fmt *fmt, int c, size_t prec, int align)
{
	char		*tmp;
	char		*ret;
	size_t		tmp_len;

	tmp_len = re_len(fmt, c, prec);
	tmp = ft_memset(ft_strnew(tmp_len), c, tmp_len);
	if (!fmt->value_len)
		return (tmp);
	if (fmt->is_value_negative && c == ' ')
		tmp[tmp_len - 1] = '-';
	else if (fmt->is_value_negative)
		tmp[0] = '-';
	if (align == 0)
		ret = ft_strsubjoin(tmp, fmt->spec_value, fmt->is_value_negative);
	else
		ret = ft_strsubjoin(fmt->spec_value, tmp, 0);
	free(tmp);
	return (ret);
}

static void		fmt_csp_width(t_pf_fmt *fmt)
{
	if (fmt->width > fmt->value_len)
	{
		fmt->spec_value = fmt_padding(
			fmt, ' ', fmt->width, (int)fmt->is_left);
		fmt->value_len = fmt->width;
	}
}

static void		fmt_diux_width(t_pf_fmt *fmt)
{
	if (fmt->is_prec && !fmt->prec &&
		!fmt->left_prec && !ft_strcmp(fmt->spec_value, "0"))
			fmt->value_len = 0;
	if (fmt->prec >= fmt->value_len)
	{
		fmt->spec_value = fmt_padding(fmt, '0', fmt->prec, 0);
		fmt->value_len = fmt->is_value_negative ?
			++fmt->prec : fmt->prec;
	}
	if (fmt->width > fmt->value_len)
	{
		if (fmt->is_zero && !fmt->is_left &&
			(!fmt->is_prec || fmt->left_prec))
			fmt->spec_value = fmt_padding(fmt, '0', fmt->width, 0);
		else
			fmt->spec_value = fmt_padding(
				fmt, ' ', fmt->width, (int)fmt->is_left);
		fmt->value_len = fmt->width;
	}
}

void			fmt_exception(t_pf_fmt *fmt, t_pf_len *len)
{
	if (ft_strchr("csp%%", fmt->specifier))
	{
		if (fmt->specifier == 'p' && fmt->is_prec &&
		!fmt->prec && !fmt->left_prec && fmt->is_null)
		{
			fmt->spec_value = ft_strsub(fmt->spec_value, 0, 2);
			fmt->value_len = ft_strlen(fmt->spec_value);
		}
		if (fmt->specifier == 's' && fmt->prec < fmt->value_len &&
			fmt->is_prec && !fmt->left_prec)
		{
			fmt->spec_value = ft_strsub(fmt->spec_value, 0, fmt->prec);
			fmt->value_len = fmt->prec;
		}
		fmt_csp_width(fmt);
	}
	else if (ft_strchr("diuxX", fmt->specifier))
		fmt_diux_width(fmt);
	write(1, fmt->spec_value, fmt->value_len);
	len->total_len += fmt->value_len;
}
