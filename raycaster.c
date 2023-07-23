/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:49:07 by moabdelo          #+#    #+#             */
/*   Updated: 2023/07/19 23:05:02 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_wall	wall(t_vars *vars, char *path)
{
	int		i;
	int		j;
	t_data	*img;
	t_wall	wall;

	img = ft_calloc(sizeof(t_data), 1);
	img->img = mlx_xpm_file_to_image(vars->mlx,
			path, &wall.width, &wall.height);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	wall.colors = malloc(wall.width * sizeof(int *));
	i = 0;
	while (i < wall.width)
	{
		j = 0;
		wall.colors[i] = malloc(wall.height * sizeof(int));
		while (j < wall.height)
		{
			wall.colors[i][j] = *(unsigned int *)dst(img,
					(int)(i), (int)(j));
			j++;
		}
		i++;
	}
	return (free(img), wall);
}

void	initialise_direction_and_wall(t_datta *data, t_vars *vars)
{
	if (data->player == 'N')
	{
		vars->p.dir_x = -1;
		vars->c.plane_y = 0.66;
	}
	if (data->player == 'S')
	{
		vars->p.dir_x = 1;
		vars->c.plane_y = -0.66;
	}
	if (data->player == 'E')
	{
		vars->p.dir_y = 1;
		vars->c.plane_x = 0.66;
	}
	if (data->player == 'W')
	{
		vars->p.dir_y = -1;
		vars->c.plane_x = -0.66;
	}
	vars->no = wall(vars, data->no);
	vars->so = wall(vars, data->so);
	vars->we = wall(vars, data->we);
	vars->ea = wall(vars, data->ea);
}

t_vars	*init_vars(t_datta *data)
{
	t_vars	*vars;

	vars = ft_calloc(sizeof(t_vars), 1);
	vars->map.content = data->map;
	vars->map.width = data->char_len;
	vars->map.height = data->map_len;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "./cub3");
	vars->img.img = mlx_new_image(vars->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	vars->p.pos_x = data->player_x;
	vars->p.pos_y = data->player_y;
	initialise_direction_and_wall(data, vars);
	vars->m.movespeed = 0.1;
	vars->m.rotspeed = PI / 16;
	return (vars);
}

void	init_color(t_datta *data, t_vars *vars)
{
	char	**str;
	t_color	c;

	str = ft_split(data->c, ',');
	if (len_of_double_pointer(str) != 3)
		printf_error("check your color");
	c.r = ft_atoi(str[0]);
	c.g = ft_atoi(str[1]);
	c.b = ft_atoi(str[2]);
	c.color = rgb(c.r, c.g, c.b);
	vars->ceiling_color = c;
	free_it(str);
	str = ft_split(data->f, ',');
	if (len_of_double_pointer(str) != 3)
		printf_error("check your color5");
	c.r = ft_atoi(str[0]);
	c.g = ft_atoi(str[1]);
	c.b = ft_atoi(str[2]);
	c.color = rgb(c.r, c.g, c.b);
	vars->floor_color = c;
	free_it(str);
}

int	main(int ac, char **av)
{
	t_datta	*data;
	t_vars	*vars;
	int		i;

	i = 0;
	data = ft_calloc(sizeof(t_datta), 1);
	if (ac == 2)
	{
		check_name_of_map(av, data);
		read_and_check_map(data);
		vars = init_vars(data);
		init_color(data, vars);
		fn_draw(vars, vars->img, &vars->p, vars->c);
		print_2d_map(vars);
		mlx_hook(vars->win, 17, 0, fn_click_on_cross, vars);
		mlx_hook(vars->win, 4, 0, fn_mouse, vars);
		mlx_hook(vars->win, 2, 0, fn_keydown, vars);
		mlx_loop(vars->mlx);
	}
	else
		error_past_args();
	return (0);
}
