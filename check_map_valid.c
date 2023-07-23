/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:11:58 by afanti            #+#    #+#             */
/*   Updated: 2023/07/20 13:41:47 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_map_cont(int s, int i, char *st)
{
	while (st[++s])
	{
		i = s;
		if (st[s] == '\n' && st[s + 1] == '\n')
		{
			while (st[++i])
			{
				if (st[i] != '\n' && st[i] != '\0')
					printf_error("your map not valid");
			}
			break ;
		}
	}
}

void	check_map_line(char *str, int i)
{
	char	*st;
	int		s;

	st = ft_calloc(sizeof(char *) * ft_strlen(str), 1);
	s = 0;
	while (str[i])
	{
		if ((str[i] == '\n' && str[i + 1] == '1')
			|| (str[i] == '\n' && str[i + 1] == ' '))
		{
			free(st);
			st = ft_calloc(sizeof(char *) * ft_strlen(str) - i, 1);
			while (str[++i])
				st[s++] = str[i];
			i--;
		}
		i++;
	}
	s = 0;
	while (st[s] == '\n')
		s++;
	check_map_cont(s, i, st);
	free(st);
}

void	check_map_if_valid(t_datta *data, int i, int s)
{
	i = -1;
	while (data->map[++i])
	{
		s = 0;
		while (data->map[i][s])
		{
			if (data->map[i][s] == '0' || data->map[i][s] == 'N'
				|| data->map[i][s] == 'S' || data->map[i][s] == 'E'
				|| data->map[i][s] == 'W')
			{
				if (s == 0 || i == 0 || s == (data->char_len - 1)
					|| i == (data->map_len - 1))
					printf_error("your map not valid check it");
				if (data->map[i][s + 1] == ' ' || data->map[i][s - 1] == ' '
					|| data->map[i + 1][s] == ' ' || data->map[i - 1][s] == ' ')
					printf_error("your map not valid check it");
			}
			else if (data->map[i][s] != '1' && data->map[i][s] != ' ')
				printf_error("your map not valid there is a new character");
			s++;
		}
	}
}
