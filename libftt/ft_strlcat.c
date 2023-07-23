/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:03:45 by moabdelo          #+#    #+#             */
/*   Updated: 2022/10/26 13:03:47 by moabdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	char	*n_src;

	n_src = (char *)src;
	if (dstsize == 0)
		return (ft_strlen(n_src) + dstsize);
	i = 0;
	len_dst = ft_strlen(dst);
	j = len_dst;
	if (len_dst > dstsize)
		return (ft_strlen(n_src) + dstsize);
	if (!src[i])
		return (len_dst + ft_strlen(n_src));
	while (n_src[i] && (i + len_dst + 1) < (dstsize))
		dst[j++] = n_src[i++];
		dst[j] = '\0';
	return (len_dst + ft_strlen(n_src));
}
