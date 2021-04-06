/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_begin_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 02:27:22 by hanjongho         #+#    #+#             */
/*   Updated: 2021/01/05 02:27:23 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_begin_char(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] == c)
		++i;
	return (i);
}
