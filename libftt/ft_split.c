/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 00:27:20 by moabdelo          #+#    #+#             */
/*   Updated: 2022/10/18 15:47:20 by moabdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_str(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] && s[i] != c)
	{
		j++;
		i++;
	}
	return (j);
}

static char	*fn_word(char const *s, char c, int i)
{
	int		j;
	char	*word;

	j = 0;
	word = (char *)malloc(len_str(s, c, i) * sizeof(char) + 1);
	if (!word)
		return (0);
	while (s[i] && s[i] != c)
		word[j++] = s[i++];
	word[j] = '\0';
	return (word);
}

static int	len_split(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			i += (len_str(s, c, i) - 1);
			j++;
		}
		i++;
	}
	return (j + 1);
}

static char	**split_cal(char const *s, char c, int i, int j)
{
	char	**result;

	if (!s)
		return (0);
	result = (char **)malloc(len_split(s, c) * sizeof(char *));
	if (!result)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			result[j] = fn_word(s, c, i);
			if (result[j++])
				i += (len_str(s, c, i) - 1);
			else
			{
				while (j)
					free(result[j--]);
				free(result);
			}
		}
		i++;
	}
	result[j] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	return (split_cal(s, c, 0, 0));
}
