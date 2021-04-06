/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_fmt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 23:45:39 by hanjongho         #+#    #+#             */
/*   Updated: 2021/01/24 01:38:25 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		parse_flags(char *str, t_pf_fmt *fmt)
{
	int			i;

	i = 0;
	while (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
			fmt->is_left = 1;
		if (str[i] == '0')
			fmt->is_zero = 1;
		i++;
	}
	return (i);
}

static int		parse_width(char *str, t_pf_fmt *fmt, va_list *ap)
{
	int			i;
	ssize_t		tmp;

	i = 0;
	if (str[i] == '*')
	{
		tmp = va_arg(*ap, int);
		if (tmp < 0)
			fmt->is_left = 1;
		fmt->width = tmp < 0 ? tmp * -1 : tmp;
		i++;
	}
	else
	{
		while (ft_isdigit(str[i]))
			i++;
		fmt->width = ft_atoi(ft_strsub(str, 0, i));
	}
	return (i);
}

static int		parse_prec(char *str, t_pf_fmt *fmt, va_list *ap)
{
	int			i;
	ssize_t		tmp;

	i = 0;
	if (str[i] == '.')
	{
		i++;
		fmt->is_prec = 1;
		if (str[i] == '*')
		{
			tmp = va_arg(*ap, int);
			fmt->prec = tmp < 0 ? 0 : tmp;
			fmt->left_prec = tmp < 0 ? tmp * -1 : 0;
			i++;
		}
		else if (ft_isdigit(str[i]))
			i += parse_numeric((str + 1), &fmt->prec);
	}
	return (i);
}

static int		parse_specifier(char *str, t_pf_fmt *fmt, va_list *ap)
{
	int			i;
	char		*specs;

	i = 0;
	specs = "cspdiuxX%%";
	if (ft_strchr(specs, str[i]))
	{
		fmt->specifier = str[i];
		set_spec_val(fmt, ap);
		i++;
	}
	return (i);
}

int				parse_fmt(char *str, t_pf_fmt *fmt, va_list *ap)
{
	int			i;

	i = 0;
	i += parse_flags((str + i), fmt);
	i += parse_width((str + i), fmt, ap);
	i += parse_prec((str + i), fmt, ap);
	i += parse_specifier((str + i), fmt, ap);
	return (i);
}
