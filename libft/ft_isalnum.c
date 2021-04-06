/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:44:38 by hanjongho         #+#    #+#             */
/*   Updated: 2020/10/07 21:38:14 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if (('0' <= c && c <= '9')
			|| ('a' <= c && c <= 'z')
			|| ('A' <= c && c <= 'Z'))
		return (1);
	return (0);
}