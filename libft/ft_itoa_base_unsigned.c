/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 02:30:51 by hanjongho         #+#    #+#             */
/*   Updated: 2021/01/13 03:00:27 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_unsigned(unsigned long long int n, int base)
{
	long	tmp;
	char	*res;
	size_t	len;

	len = ft_int_len(n);
	if (!(res = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	res[len] = '\0';
	while (len--)
	{
		tmp = n % base;
		res[len] = (tmp < 10) ? tmp + '0' : tmp + '7';
		n /= base;
	}
	return (res);
}
