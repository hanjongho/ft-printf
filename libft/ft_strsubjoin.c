/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 02:27:14 by hanjongho         #+#    #+#             */
/*   Updated: 2021/01/05 02:27:15 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubjoin(char const *s1, char const *s2, unsigned int s2_start)
{
	size_t	s1len;
	size_t	s2len;
	char	*subjoin;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2) - s2_start;
	if (!(subjoin = (char *)malloc((s1len + s2len + 1) * sizeof(char))))
		return (NULL);
	while (*s1)
		*subjoin++ = *s1++;
	s2 += s2_start;
	while (*s2)
		*subjoin++ = *s2++;
	*subjoin = '\0';
	return (subjoin - (s1len + s2len));
}
