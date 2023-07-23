/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:05:27 by moabdelo          #+#    #+#             */
/*   Updated: 2022/10/26 13:05:30 by moabdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	locate_f(char *haystack, char *needle, size_t i)
{
	size_t	j;

	j = 0;
	while (needle[j])
	{
		if (needle[j] != haystack[i])
			return (-1);
		j++;
		i++;
	}
	return (i - j);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*n_haystack;
	char	*n_needle;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (!haystack && len == 0)
		return (0);
	n_needle = (char *)needle;
	n_haystack = (char *)haystack;
	while (n_haystack[i] && i + ft_strlen(n_needle) <= len)
	{
		if (locate_f(n_haystack, n_needle, i) >= 0)
			return (n_haystack + locate_f(n_haystack, n_needle, i));
		i++;
	}
	return (0);
}
