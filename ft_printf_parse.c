/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 23:45:44 by hanjongho         #+#    #+#             */
/*   Updated: 2021/01/23 19:16:14 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_null(t_pf_fmt *fmt, t_pf_len *len)
{
	len->total_len += fmt->width;
	if (fmt->width)
	{
		if (fmt->is_left)
			write(1, "\0", 1);
		while (--fmt->width > 0)
			write(1, " ", 1);
		if (!fmt->is_left)
			write(1, "\0", 1);
		return ;
	}
	write(1, "\0", 1);
	len->total_len++;
}

static void	check_fmt(t_pf_fmt *fmt, t_pf_len *len)
{
	if (fmt->specifier == 'c' && fmt->is_null)
		add_null(fmt, len);
	else
		fmt_exception(fmt, len);
}

int			parse_numeric(char *str, size_t *prec)
{
	int		i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	*prec = ft_atoi(ft_strsub(str, 0, i));
	return (i);
}

void		parse_str(char *str, t_pf_fmt *fmt, t_pf_len *len, va_list *ap)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			reset_fmt(fmt);
			i += parse_fmt((str + i), fmt, ap);
			if (fmt->specifier == '\0')
				return ;
			check_fmt(fmt, len);
		}
		j = 0;
		while (str[i] != '%' && str[i] != '\0')
		{
			len->total_len++;
			i++;
			j++;
		}
		write(1, str + i - j, j);
	}
}
