/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:49:54 by moabdelo          #+#    #+#             */
/*   Updated: 2023/07/19 21:30:34 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_player(int x, int y, int r, t_vars *vars)
{
	int		i;
	int		j;
	int		dsq;
	t_color	c;

	i = x - r;
	c = vars->ceiling_color;
	while (i <= x + r)
	{
		j = y - r;
		while (j <= y + r)
		{
			dsq = (x + r - i) * (x + r - i) + (y - j) * (y - j)
				+ (r + i - x) * (r + i - x) + (y - j) * (y - j);
			if (dsq <= 4 * r * r)
				pixel_put(&vars->img, i, j,
					rgb(255 - c.r, 255 - c.g, 100));
			j++;
		}
		i++;
	}
	i = -1;
	while (++i <= 6)
		pixel_put(&vars->img, x + vars->p.dir_y * i,
			y + vars->p.dir_x * i, rgb(255 - c.r, 100, 255 - c.b));
}

void	print_2d_map(t_vars *vars)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 8;
	x = vars->p.pos_y * 8 - 100;
	while (i < 200)
	{
		y = vars->p.pos_x * 8 - 100;
		j = 8;
		while (j < 200)
		{
			if (y >= 0 && x / 8 < vars->map.width && x >= 0
				&& y / 8 < vars->map.height
				&& vars->map.content[y / 8][x / 8] == '0')
				pixel_put(&vars->img, i, j, rgb(100, 100, 255));
			y++;
			j++;
		}
		x++;
		i++;
	}
	print_player(108, 108, 4, vars);
}
