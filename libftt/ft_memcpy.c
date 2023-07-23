/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:02:52 by moabdelo          #+#    #+#             */
/*   Updated: 2022/10/25 14:02:54 by moabdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*n_src;
	char	*n_dest;

	i = 0;
	n_src = (char *)src;
	n_dest = (char *)dest;
	if ((n_src == 0) && (n_dest == 0))
		return (0);
	while (i < n)
	{
		n_dest[i] = n_src[i];
		i++;
	}
	return (n_dest);
}
