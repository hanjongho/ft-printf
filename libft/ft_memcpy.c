/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:45:14 by hanjongho         #+#    #+#             */
/*   Updated: 2020/10/12 02:53:53 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char		*d;
	unsigned char		*s;
	size_t				i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (0);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i < num)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
