/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 02:34:00 by hanjongho         #+#    #+#             */
/*   Updated: 2021/01/05 02:34:01 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *cs1;
	unsigned char *cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	if (!cs1 && !cs2)
		return (0);
	while (*cs1 == *cs2)
	{
		cs1++;
		cs2++;
		if (!*cs1 && !*cs2)
			return (0);
	}
	return (*cs1 - *cs2);
}
