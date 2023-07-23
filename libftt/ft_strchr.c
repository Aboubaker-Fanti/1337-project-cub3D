/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:28:18 by moabdelo          #+#    #+#             */
/*   Updated: 2022/10/14 11:31:52 by moabdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	position_c(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = position_c(s, (char)c);
	if ((char)c != '\0' && s[i] == '\0')
		return (0);
	return ((char *)(s + i));
}
