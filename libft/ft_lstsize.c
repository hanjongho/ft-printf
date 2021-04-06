/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:13:08 by hanjongho         #+#    #+#             */
/*   Updated: 2020/10/13 18:15:40 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int cnt;

	if (!lst)
		return (0);
	cnt = 1;
	while (lst->next)
	{
		lst = lst->next;
		cnt++;
	}
	return (cnt);
}
