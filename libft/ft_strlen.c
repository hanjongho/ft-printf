/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:44:53 by hanjongho         #+#    #+#             */
/*   Updated: 2021/01/05 02:38:53 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
