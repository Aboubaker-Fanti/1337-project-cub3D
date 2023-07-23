/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:32:22 by afanti            #+#    #+#             */
/*   Updated: 2023/07/19 19:35:01 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_texture_valid_here(char *str)
{
	int		i;
	char	*st;
	int		fd;

	i = 0;
	st = ft_strrchr(str, '.');
	if (st == NULL)
		printf_error("your texture name not valid");
	else
		if (ft_strncmp(st, ".xpm") != 0)
			printf_error("check your tecture name should be end with .xpm");
	fd = open(str, O_RDONLY, 0777);
	if (fd < 0)
		printf_error("check your tecture is not exists");
	close(fd);
}

void	check_texture_valid(t_datta *data)
{
	check_texture_valid_here(data->so);
	check_texture_valid_here(data->no);
	check_texture_valid_here(data->we);
	check_texture_valid_here(data->ea);
}

void	check_player_position(t_datta *data)
{
	int	x;
	int	y;
	int	d;

	x = -1;
	d = 0;
	while (data->map[++x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'N' || data->map[x][y] == 'S'
				|| data->map[x][y] == 'E' || data->map[x][y] == 'W')
			{
				d++;
				data->player_x = x;
				data->player_y = y;
				data->player = data->map[x][y];
				data->map[x][y] = '0';
			}
			y++;
		}
	}
	if (d > 1 || d == 0)
		printf_error("there is more than one player or less than one check it");
}
