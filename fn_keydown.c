/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_keydown.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:18:42 by moabdelo          #+#    #+#             */
/*   Updated: 2023/07/19 21:12:07 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fn_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	fn_keydown(int keycode, t_vars *vars)
{
	if (keycode == 53)
		fn_close(vars);
	else
		fn_move(keycode, vars);
	return (0);
}

void	fn_clear_window(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = 0;
		while (j < SCREEN_HEIGHT)
			pixel_put(&vars->img, i, j++, rgb(50, 50, 50));
		i++;
	}
}

void	pos_wall_x_call(t_wall wall, t_draw_wall *w, t_ray *r, t_player *p)
{
	double	pos_wall;

	if (w->side == 0)
		pos_wall = r->len * r->ray_dir.y + p->pos_y;
	else
		pos_wall = r->len * r->ray_dir.x + p->pos_x;
	pos_wall = fabs(pos_wall - (int)pos_wall);
	w->pos_x = ((int)(pos_wall * (wall.width)));
	if ((w->side == 0 && r->ray_dir.x > 0)
		|| (w->side == 1 && r->ray_dir.y < 0))
		w->pos_x = (int)(((wall.width) - w->pos_x - 1));
}

void	pos_wall_x(t_vars *vars, t_draw_wall *w, t_ray *r, t_player *p)
{
	if (w->side == 0 && r->ray_dir.x > 0)
		pos_wall_x_call(vars->no, w, r, p);
	else if (w->side == 0)
		pos_wall_x_call(vars->so, w, r, p);
	else if (r->ray_dir.y > 0)
		pos_wall_x_call(vars->we, w, r, p);
	else
		pos_wall_x_call(vars->ea, w, r, p);
}
