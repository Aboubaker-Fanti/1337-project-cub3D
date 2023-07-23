/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:11:00 by moabdelo          #+#    #+#             */
/*   Updated: 2022/10/26 13:11:54 by moabdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			len_s;
	char			*sub_s;

	i = 0;
	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if ((size_t)start >= len_s)
		return (ft_strdup(""));
	else if (start + len > len_s)
		sub_s = (char *)malloc((len_s - start) * sizeof(char) + 1);
	else
		sub_s = (char *)malloc(len * sizeof(char) + 1);
	if (!sub_s)
		return (0);
	while (s[start + i] && (i < len))
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
