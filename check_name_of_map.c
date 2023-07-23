/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_of_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:47:21 by afanti            #+#    #+#             */
/*   Updated: 2023/07/19 18:14:59 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	len_of_double_pointer(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	check_name_of_map(char **av, t_datta *data)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strrchr(av[1], '.');
	if (str == NULL)
		printf_error("check your map name");
	else
		if (ft_strncmp(str, ".cub") != 0)
			printf_error("check your map name should be end with .rt");
	data->map_fd = open(av[1], O_RDONLY, 0777);
	if (data->map_fd < 0)
		printf_error("there is no file with this name!");
}

void	equal_map(t_datta *data, int i, int s)
{
	data->char_len = 0;
	while (data->map[i])
	{
		s = 0;
		while (data->map[i][s])
			s++;
		if (data->char_len < s)
			data->char_len = s;
		i++;
	}
	i = 0;
	while (data->map[i])
	{
		while (1)
		{
			s = ft_strlen(data->map[i]);
			if (s == data->char_len)
				break ;
			if (s != data->char_len)
				data->map[i] = t_strjoin(data->map[i], " ");
		}
		i++;
	}
	data->map_len = i;
}
