/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:45:02 by hanjongho         #+#    #+#             */
/*   Updated: 2020/10/22 03:15:25 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t count)
{
	unsigned char	*dest_;
	unsigned char	*src_;
	unsigned char	c_;
	size_t			i;

	i = 0;
	dest_ = (unsigned char *)dest;
	src_ = (unsigned char *)src;
	c_ = c;
	while (i < count)
	{
		dest_[i] = src_[i];
		if (src_[i] == c_)
			return ((void*)dest + i + 1);
		i++;
	}
	return (NULL);
}
