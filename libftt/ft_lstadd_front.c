/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:30:15 by moabdelo          #+#    #+#             */
/*   Updated: 2022/10/28 18:32:29 by moabdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*t;

	if (!new)
		return ;
	if (*lst)
	{
		t = *lst;
		*lst = new;
		new->next = t;
		return ;
	}
	*lst = new;
}
