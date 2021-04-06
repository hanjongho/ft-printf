/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:45:06 by hanjongho         #+#    #+#             */
/*   Updated: 2020/10/12 01:57:00 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*ptr1_;
	unsigned char	*ptr2_;
	size_t			i;

	i = 0;
	ptr1_ = (unsigned char *)ptr1;
	ptr2_ = (unsigned char *)ptr2;
	while (i < num)
	{
		if (ptr1_[i] != ptr2_[i])
			return (ptr1_[i] - ptr2_[i]);
		i++;
	}
	return (0);
}
