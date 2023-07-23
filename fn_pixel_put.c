/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:29:41 by moabdelo          #+#    #+#             */
/*   Updated: 2023/07/19 22:47:40 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	free_it(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	fn_put_image(char *relative_path, t_vars *vars, int i, int j)
{
	void	*image;
	int		img_width;
	int		img_height;

	image = mlx_xpm_file_to_image(vars->mlx,
			relative_path, &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, image, i, j);
}

char	*dst(t_data *data, int x, int y)
{
	return (data->addr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8)));
}
