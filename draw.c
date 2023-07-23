/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:49:48 by moabdelo          #+#    #+#             */
/*   Updated: 2023/07/19 21:10:47 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dimension_wall(t_draw_wall *wall, t_ray r)
{
	wall->line_height = (int)(SCREEN_HEIGHT / r.len);
	wall->draw_start = SCREEN_HEIGHT / 2 - wall->line_height / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_height / 2 + SCREEN_HEIGHT / 2;
	if (wall->draw_end >= SCREEN_HEIGHT)
		wall->draw_end = SCREEN_HEIGHT;
	wall->d_draw_start = wall->draw_start;
	wall->d_draw_end = wall->draw_end;
	wall->d_height = wall->line_height;
}

void	ver_line_call(t_vars *vars, int i, t_draw_wall w, t_wall wall)
{
	double	j;
	double	y;

	j = 0;
	while (j < w.d_draw_start)
		pixel_put(&vars->img, i, j++, vars->ceiling_color.color);
	if (w.d_height >= SCREEN_HEIGHT)
		w.d_draw_start = ((w.d_height - SCREEN_HEIGHT)
				/ w.d_height) * (wall.height);
	while (j < w.d_draw_end)
	{
		y = (wall.height) * ((j - w.d_draw_start) / w.d_height);
		if (w.d_height >= SCREEN_HEIGHT)
			y = wall.height * j / w.d_height + w.d_draw_start / 2;
		pixel_put(&vars->img, i, j++, wall.colors[w.pos_x][(int)(y)]);
	}
	while (j < SCREEN_HEIGHT)
		pixel_put(&vars->img, i, j++, vars->floor_color.color);
}

void	ver_line(t_vars *vars, int i, t_draw_wall w, t_ray r)
{
	if (w.side == 0 && r.ray_dir.x > 0)
		ver_line_call(vars, i, w, vars->no);
	else if (w.side == 0)
		ver_line_call(vars, i, w, vars->so);
	else if (r.ray_dir.y > 0)
		ver_line_call(vars, i, w, vars->we);
	else
		ver_line_call(vars, i, w, vars->ea);
}

void	fn_draw(t_vars *vars, t_data img, t_player *p, t_camera c)
{
	int				i;
	t_ray			r;
	t_draw_wall		wall;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		initial_params_calcul(&r, i, p, c);
		initial_params_calcul_len_ray(p, &r);
		side_wall_len_ray(&wall, &r, p, vars);
		pos_wall_x(vars, &wall, &r, p);
		dimension_wall(&wall, r);
		ver_line(vars, i, wall, r);
		i++;
	}
	print_2d_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}
