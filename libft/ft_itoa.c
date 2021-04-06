/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 20:05:26 by hanjongho         #+#    #+#             */
/*   Updated: 2020/10/22 18:38:51 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	str_fill(char *str, int n, int i)
{
	if (n > 9)
	{
		str[i] = n % 10 + '0';
		str_fill(str, n / 10, i - 1);
	}
	else
		str[i] = n + '0';
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		x;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	x = n;
	len = (n < 0) ? 2 : 1;
	while (x /= 10)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[len] = '\0';
	str_fill(str, n, len - 1);
	return (str);
}
