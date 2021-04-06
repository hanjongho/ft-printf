/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:45:24 by hanjongho         #+#    #+#             */
/*   Updated: 2020/10/13 16:34:29 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int ch)
{
	char	*start;

	start = (char *)str;
	while (*str++)
		;
	while (--str != start && *str != (char)ch)
		;
	if (*str == (char)ch)
		return ((char *)str);
	return (NULL);
}
