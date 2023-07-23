/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:56:15 by moabdelo          #+#    #+#             */
/*   Updated: 2022/11/02 12:56:18 by moabdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{	
	t_list	*newlist;
	t_list	*node;
	t_list	*t;

	if (!lst)
		return (0);
	t = lst;
	newlist = 0;
	while (t)
	{
		node = ft_lstnew(f(t->content));
		if (!(node))
		{
			ft_lstclear(&newlist, del);
			return (0);
		}
		ft_lstadd_back(&newlist, node);
		t = t->next;
	}
	return (newlist);
}
