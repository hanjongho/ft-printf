/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 20:00:49 by hanjongho         #+#    #+#             */
/*   Updated: 2020/10/27 14:49:50 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		exist(char const c, char charset)
{
	if (charset == c)
		return (1);
	return (0);
}

int		cnt_strlen(char const *str, char charset)
{
	int i;
	int cnt;
	int check;

	cnt = 0;
	i = 0;
	check = 0;
	while (str[i])
	{
		if (!check && !(exist(str[i], charset)))
		{
			check = 1;
			cnt++;
		}
		else if (check && exist(str[i], charset))
			check = 0;
		i++;
	}
	return (cnt);
}

void	ft_free(char **str, int d)
{
	int		i;

	i = -1;
	while (++i < d && str[i])
		free(str[i]);
	free(str);
}

char	**str_split(char const *str, char charset, int len, char **dest)
{
	int st;
	int end;
	int cnt;

	st = 0;
	cnt = 0;
	while (str[st] && cnt < len)
	{
		while (exist(str[st], charset) && str[st])
			st++;
		end = st;
		while (!exist(str[end], charset) && str[end])
			end++;
		if (!(dest[cnt] = (char *)malloc(sizeof(char) * (end - st + 1))))
		{
			ft_free(dest, cnt);
			return (NULL);
		}
		ft_memcpy(&dest[cnt][0], &str[st], end - st);
		dest[cnt++][end - st] = 0;
		st = end;
	}
	dest[cnt] = 0;
	return (dest);
}

char	**ft_split(char const *str, char charset)
{
	int		cnt;
	char	**split;

	if (!str)
		return (NULL);
	cnt = cnt_strlen(str, charset);
	if (!(split = (char **)malloc(sizeof(char *) * (cnt + 1))))
		return (NULL);
	return (str_split(str, charset, cnt, split));
}
