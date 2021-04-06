/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:33:45 by hanjongho         #+#    #+#             */
/*   Updated: 2020/10/27 14:54:19 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check(char a, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (a == set[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_count(char const *s1, char const *set)
{
	int		i;
	int		j;

	i = 0;
	while (ft_check(s1[i], set))
		i++;
	j = i;
	while (s1[j])
		j++;
	if (i == j)
		return (0);
	j--;
	while (ft_check(s1[j], set))
		j--;
	return (j - i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		count;
	char	*str;

	if (!s1)
		return (NULL);
	count = ft_count(s1, set);
	if (!(str = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	i = 0;
	while (ft_check(s1[i], set))
		i++;
	j = -1;
	while (++j < count)
		str[j] = s1[i + j];
	str[j] = 0;
	return (str);
}
