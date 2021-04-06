/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 02:30:56 by hanjongho         #+#    #+#             */
/*   Updated: 2021/01/20 23:26:40 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_unsigned(unsigned int n)
{
	unsigned int		num;
	char				*res;
	int					len;

	num = n;
	len = ft_int_len(num);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (num == 0)
		res[0] = '0';
	res[len] = '\0';
	while (num != 0)
	{
		res[--len] = (num % 10) < 0 ? (num % 10) * -1 + '0' : num % 10 + '0';
		num = num / 10;
	}
	return (res);
}
