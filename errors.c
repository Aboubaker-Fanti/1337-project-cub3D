/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:49:37 by moabdelo          #+#    #+#             */
/*   Updated: 2023/07/20 13:44:35 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	printf_error(char *str)
{
	write (2, "Error\n", 6);
	ft_putstr_fd(str, 2);
	exit (1);
}

void	error_past_args(void)
{
	write (2, "Error\n", 7);
	ft_putstr_fd("there is more than or less than 2 argement\n", 2);
	ft_putstr_fd("your argement should be \n => name of the", 2);
	ft_putstr_fd("program \n => your map name\n", 2);
}

void	check_deplicate(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i][0] != ' ' && str[i][0] != '1' && str[i][0] != '\n')
			printf_error("map not valid check it55");
		i++;
	}
}

void	split_map_with_ide(t_datta *data)
{
	int	i;
	int	s;

	i = -1;
	s = len_of_double_pointer(data->map2d);
	data->ide = (char **)ft_calloc(sizeof(char *) * 7, 1);
	data->map = (char **)ft_calloc(sizeof(char *) * (s - 5), 1);
	while (++i < 6)
		data->ide[i] = ft_strdup(data->map2d[i]);
	s = 0;
	while (data->map2d[i])
	{
		data->map[s] = ft_strdup(data->map2d[i]);
		i++;
		s++;
	}
	check_deplicate(data->map);
	equal_map(data, 0, 0);
	split_ide(data);
	check_map_ide_if_clear(data, 0);
	check_map_if_valid(data, 0, 0);
}

void	read_and_check_map(t_datta *data)
{
	int		i;
	char	*str;

	str = ft_calloc(sizeof(char) * 1, 1);
	i = 0;
	while (1)
	{
		data->str_line = get_next_line(data->map_fd);
		if (data->str_line == NULL)
			break ;
		str = t_strjoin(str, data->str_line);
		free(data->str_line);
		data->str_line = NULL;
	}
	check_map_line(str, 0);
	data->map2d = ft_split(str, '\n');
	free(str);
	split_map_with_ide(data);
	check_player_position(data);
}
