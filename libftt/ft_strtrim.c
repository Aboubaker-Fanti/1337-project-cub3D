/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:07:11 by moabdelo          #+#    #+#             */
/*   Updated: 2022/10/26 13:09:15 by moabdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_contain(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
			return (1);
	}
	return (0);
}

static char	*trim_str(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		index;
	int		nb;
	char	*trim_str;

	i = 0;
	index = 0;
	j = ft_strlen(s1);
	while (s1[i] && check_contain(set, s1[i]))
		i++;
	while (j > (i - 1) && check_contain(set, s1[j - 1]))
		j--;
	nb = j - i;
	trim_str = (char *)malloc(nb * sizeof(char) + 1);
	if (!trim_str)
		return (0);
	while (index < nb)
		trim_str[index++] = s1[i++];
	trim_str[index] = '\0';
	return (trim_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	if (!s1[0])
		return (ft_strdup(""));
	return (trim_str(s1, set));
}
