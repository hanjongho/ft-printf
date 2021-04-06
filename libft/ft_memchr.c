/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:45:04 by hanjongho         #+#    #+#             */
/*   Updated: 2020/10/19 02:51:48 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *ptr, int value, size_t num)
{
	char		*ptr_;
	size_t		i;

	ptr_ = (char*)ptr;
	i = 0;
	while (i < num)
	{
		if (*(ptr_ + i) == value)
			return (ptr_ + i);
		i++;
	}
	return (NULL);
}
