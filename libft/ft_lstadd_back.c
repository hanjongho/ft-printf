/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjongho <hanjongho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:11:45 by hanjongho         #+#    #+#             */
/*   Updated: 2020/10/18 23:18:25 by hanjongho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	l = *lst;
	if (!new || !lst)
		return ;
	else if (!l)
	{
		*lst = new;
		return ;
	}
	while (l->next)
		l = l->next;
	l->next = new;
	new->next = NULL;
}
