/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:50:11 by moabdelo          #+#    #+#             */
/*   Updated: 2023/07/17 19:03:17 by moabdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_left(t_vars *vars)
{
	if (vars->map.content[(int)(vars->p.pos_x + vars->p.dir_y * 0.3)]
		[(int)vars->p.pos_y] == '0')
		vars->p.pos_x += vars->p.dir_y * vars->m.movespeed;
	if (vars->map.content[(int)vars->p.pos_x]
		[(int)(vars->p.pos_y - vars->p.dir_x * 0.3)] == '0')
		vars->p.pos_y -= vars->p.dir_x * vars->m.movespeed;
}

void	move_right(t_vars *vars)
{
	if (vars->map.content[(int)(vars->p.pos_x - vars->p.dir_y * 0.3)]
		[(int)vars->p.pos_y] == '0')
		vars->p.pos_x -= vars->p.dir_y * vars->m.movespeed;
	if (vars->map.content[(int)vars->p.pos_x]
		[(int)(vars->p.pos_y + vars->p.dir_x * 0.3)] == '0')
		vars->p.pos_y += vars->p.dir_x * vars->m.movespeed;
}

void	move_up(t_vars *vars)
{
	double	*x;
	double	*y;
	double	dir_x;
	double	dir_y;

	x = &vars->p.pos_x;
	y = &vars->p.pos_y;
	dir_x = vars->p.dir_x;
	dir_y = vars->p.dir_y;
	if (vars->map.content[(int)*x][(int)(*y + dir_y * 0.3)] == '0')
		vars->p.pos_y += vars->p.dir_y * vars->m.movespeed;
	if (vars->map.content[(int)(*x + dir_x * 0.3)][(int)*y] == '0')
		vars->p.pos_x += vars->p.dir_x * vars->m.movespeed;
}

void	move_down(t_vars *vars)
{
	double	*x;
	double	*y;
	double	dir_x;
	double	dir_y;

	x = &vars->p.pos_x;
	y = &vars->p.pos_y;
	dir_x = vars->p.dir_x;
	dir_y = vars->p.dir_y;
	if (vars->map.content[(int)*x][(int)(*y - dir_y * 0.3)] == '0')
		vars->p.pos_y -= vars->p.dir_y * vars->m.movespeed;
	if (vars->map.content[(int)(*x - dir_x * 0.3)][(int)*y] == '0')
		vars->p.pos_x -= vars->p.dir_x * vars->m.movespeed;
}

void	fn_move(int keycode, t_vars *vars)
{
	if (keycode == 2)
		move_left(vars);
	if (keycode == 0)
		move_right(vars);
	if (keycode == 13)
		move_up(vars);
	else if (keycode == 1)
		move_down(vars);
	else if (keycode == 124)
		retate_left(vars);
	else if (keycode == 123)
		retate_right(vars);
	fn_clear_window(vars);
	mlx_clear_window(vars->mlx, vars->win);
	fn_draw(vars, vars->img, &vars->p, vars->c);
}
