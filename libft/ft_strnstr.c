/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:45:22 by hanjongho         #+#    #+#             */
/*   Updated: 2020/10/27 16:59:30 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t		i;
	size_t		l;

	i = 0;
	l = ft_strlen(little);
	if (!l)
		return (big);
	while (big[i] && i + l <= len)
	{
		if (big[i] == *little && !ft_memcmp(&big[i], little, l))
			return (&big[i]);
		i++;
	}
	return (NULL);
}
