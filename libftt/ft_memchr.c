/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:17:24 by moabdelo          #+#    #+#             */
/*   Updated: 2022/10/25 14:17:39 by moabdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;

	dest = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (dest[i] == (unsigned char)c)
			return (dest + i);
		i++;
	}
	if (c == '\0' && i < n)
		return (dest + i);
	return (0);
}
