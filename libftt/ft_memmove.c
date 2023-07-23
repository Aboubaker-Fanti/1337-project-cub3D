/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:11:12 by moabdelo          #+#    #+#             */
/*   Updated: 2022/10/25 14:12:09 by moabdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*n_src;
	char		*n_dest;

	n_src = (const char *)src;
	n_dest = (char *)dest;
	if (dest == src)
		return (dest);
	if (dest > src)
	{
		i = n - 1;
		while (i + 1)
		{
			*(n_dest + i) = *(n_src + i);
			i--;
		}
		return (n_dest);
	}
	i = 0;
	while (i < n)
	{
		*(n_dest + i) = *(n_src + i);
		i++;
	}
	return (n_dest);
}
