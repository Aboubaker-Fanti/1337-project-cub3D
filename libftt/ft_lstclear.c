/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:45:59 by moabdelo          #+#    #+#             */
/*   Updated: 2022/10/28 18:48:19 by moabdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;
	t_list	*t2;

	if (!lst | !del)
		return ;
	t = *lst;
	while (t)
	{
		del(t->content);
		t2 = t->next;
		free(t);
		t = t2;
	}
	*lst = 0;
}
