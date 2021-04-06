/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 02:36:36 by hanjongho         #+#    #+#             */
/*   Updated: 2021/01/12 01:31:05 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_int_len(long int n)
{
	size_t len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		n = n / 10;
		++len;
	}
	return (len);
}