/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 00:11:57 by hanjongho         #+#    #+#             */
/*   Updated: 2020/10/18 23:19:25 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*del_node;

	if (!lst)
		return ;
	while (*lst)
	{
		del_node = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		*lst = del_node;
	}
}
