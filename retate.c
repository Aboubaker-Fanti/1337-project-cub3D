/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:48:52 by moabdelo          #+#    #+#             */
/*   Updated: 2023/07/17 22:27:28 by moabdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	retate_left(t_vars *vars)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vars->p.dir_x;
	old_plane_x = vars->c.plane_x;
	vars->p.dir_x = vars->p.dir_x * cos(-vars->m.rotspeed)
		- vars->p.dir_y * sin(-vars->m.rotspeed);
	vars->p.dir_y = old_dir_x * sin(-vars->m.rotspeed)
		+ vars->p.dir_y * cos(-vars->m.rotspeed);
	vars->c.plane_x = vars->c.plane_x * cos(-vars->m.rotspeed)
		- vars->c.plane_y * sin(-vars->m.rotspeed);
	vars->c.plane_y = old_plane_x * sin(-vars->m.rotspeed)
		+ vars->c.plane_y * cos(-vars->m.rotspeed);
}

void	retate_right(t_vars *vars)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vars->p.dir_x;
	old_plane_x = vars->c.plane_x;
	vars->p.dir_x = vars->p.dir_x * cos(vars->m.rotspeed)
		- vars->p.dir_y * sin(vars->m.rotspeed);
	vars->p.dir_y = old_dir_x * sin(vars->m.rotspeed)
		+ vars->p.dir_y * cos(vars->m.rotspeed);
	vars->c.plane_x = vars->c.plane_x * cos(vars->m.rotspeed)
		- vars->c.plane_y * sin(vars->m.rotspeed);
	vars->c.plane_y = old_plane_x * sin(vars->m.rotspeed)
		+ vars->c.plane_y * cos(vars->m.rotspeed);
}

int	fn_mouse(int button, int x, int y, t_vars *vars)
{
	(void)button;
	(void)y;
	if (x > SCREEN_WIDTH / 2)
		retate_left(vars);
	else
		retate_right(vars);
	fn_clear_window(vars);
	mlx_clear_window(vars->mlx, vars->win);
	fn_draw(vars, vars->img, &vars->p, vars->c);
	return (0);
}

int	fn_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
