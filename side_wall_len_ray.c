/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_wall_len_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:44:52 by moabdelo          #+#    #+#             */
/*   Updated: 2023/07/20 12:07:25 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	initial_params_calcul(t_ray *r, int i, t_player *p, t_camera c)
{
	r->camera_x = 2 * i / (double)SCREEN_WIDTH - 1;
	r->ray_dir.x = p->dir_x + c.plane_x * r->camera_x;
	r->ray_dir.y = p->dir_y + c.plane_y * r->camera_x;
	p->map_pos.x = (int)p->pos_x;
	p->map_pos.y = (int)p->pos_y;
	if (p->pos_x - p->map_pos.x < 0.01)
		p->pos_x += 0.01;
	if (p->pos_y - p->map_pos.y < 0.01)
		p->pos_y += 0.01;
	r->hit = 0;
	r->delta_dist_x = 1e30;
	if (r->ray_dir.x != 0)
		r->delta_dist_x = fabs(1 / r->ray_dir.x);
	r->delta_dist_y = 1e30;
	if (r->ray_dir.y != 0)
		r->delta_dist_y = fabs(1 / r->ray_dir.y);
}

void	initial_params_calcul_len_ray(t_player *p, t_ray *r)
{
	r->step_x = 1;
	r->side_pos_x = (p->map_pos.x + 1.0 - p->pos_x);
	if (r->ray_dir.x < 0)
	{
		r->step_x = -1;
		r->side_pos_x = (p->pos_x - p->map_pos.x);
	}
	r->step_y = 1;
	r->side_pos_y = (p->map_pos.y + 1.0 - p->pos_y);
	if (r->ray_dir.y < 0)
	{
		r->step_y = -1;
		r->side_pos_y = (p->pos_y - p->map_pos.y);
	}
	r->side_dist_x = r->side_pos_x * r->delta_dist_x;
	r->side_dist_y = r->side_pos_y * r->delta_dist_y;
}

void	side_wall_len_ray(t_draw_wall *wall, t_ray *r, t_player *p, t_vars *v)
{
	while (r->hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			p->map_pos.x += r->step_x;
			wall->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			p->map_pos.y += r->step_y;
			wall->side = 1;
		}
		if (v->map.content[p->map_pos.x][p->map_pos.y] == '1')
			r->hit = 1;
	}
	if (wall->side == 0)
		r->len = r->side_dist_x - r->delta_dist_x;
	else
		r->len = r->side_dist_y - r->delta_dist_y;
}
