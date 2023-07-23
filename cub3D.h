/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:46:59 by moabdelo          #+#    #+#             */
/*   Updated: 2023/07/20 15:26:28 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "get_next_line.h"

typedef struct t_datta{
	char	**map2d;
	char	*str_line;
	int		map_fd;
	char	**map;
	char	**ide;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		map_len;
	int		char_len;
	int		player_x;
	int		player_y;
	char	player;
}				t_datta;

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 960
// # define SCREEN_WIDTH 640
// # define SCREEN_HEIGHT 480
# define SQUARE_SIDE 12
# define PI 3.14159265358979323846

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	t_coordinate	map_pos;
	double			dir_x;
	double			dir_y;
}	t_player;

typedef struct s_camera
{
	double	plane_x;
	double	plane_y;
	double	fov;
}	t_camera;

typedef struct s_move
{
	double	movespeed;
	double	rotspeed;
}	t_move;

typedef struct s_color {
	int	r;
	int	g;
	int	b;
	int	color;
}	t_color;

typedef struct s_arg
{
	t_player	player;
	t_camera	camera;
	t_move		move;
}	t_arg;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_wall
{
	int	**colors;
	int	height;
	int	width;
}	t_wall;

typedef struct s_map
{
	char		**content;
	int			height;
	int			width;
}	t_map;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_data		img;
	t_data		map_img;
	t_wall		no;
	t_wall		so;
	t_wall		we;
	t_wall		ea;
	t_color		ceiling_color;
	t_color		floor_color;
	t_player	p;
	t_move		m;
	t_camera	c;
	t_map		map;
}				t_vars;

typedef struct s_vector
{
	double	len;
	double	x;
	double	y;
}	t_vector;

typedef struct s_draw_wall
{
	int		draw_start;
	int		draw_end;
	int		line_height;
	int		side;
	int		pos_x;
	double	d_draw_start;
	double	d_draw_end;
	double	d_height;
}	t_draw_wall;

typedef struct s_ray
{
	t_vector		ray_dir;
	double			len;
	double			camera_x;
	double			side_dist_x;
	double			side_dist_y;
	double			side_pos_x;
	double			side_pos_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
	int				hit;	
}	t_ray;

// typedef struct 

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int		rgb(int r, int g, int b);
void	pixel_put(t_data *data, int x, int y, int color);
void	error_past_args(void);
void	fn_draw(t_vars *vars, t_data img, t_player *p, t_camera c);
int		fn_click_on_cross(t_vars *vars);
int		fn_keydown(int keycode, t_vars *vars);
void	fn_move(int keycode, t_vars *vars);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2);
void	check_name_of_map(char **av, t_datta *data);
void	printf_error(char *str);
void	read_and_check_map(t_datta *data);
char	**ft_split(char const *s, char c);
int		len_of_double_pointer(char **str);
int		ft_isdigit_or(int c);
int		ft_atoi(const char *str);
void	free_it(char **str);
void	check_texture_valid(t_datta *data);
void	check_map_if_valid(t_datta *data, int i, int s);
void	equal_map(t_datta *data, int i, int s);
void	check_map_line(char *str, int i);
void	check_player_position(t_datta *data);
int		fn_mouse(int button, int x, int y, t_vars *vars);
void	print_2d_map(t_vars *vars);
void	fn_move(int keycode, t_vars *vars);
int		fn_mouse(int button, int x, int y, t_vars *vars);
void	fn_clear_window(t_vars *vars);
void	retate_right(t_vars *vars);
void	retate_left(t_vars *vars);
void	fn_draw(t_vars *vars, t_data img, t_player *p, t_camera c);
void	pos_wall_x(t_vars *vars, t_draw_wall *wall, t_ray *r, t_player *p);
void	side_wall_len_ray(t_draw_wall *wall, t_ray *r, t_player *p, t_vars *v);
void	initial_params_calcul(t_ray *r, int i, t_player *p, t_camera c);
void	initial_params_calcul_len_ray(t_player *p, t_ray *r);
void	printf_error(char *str);
void	free_it(char **str);
void	fn_put_image(char *relative_path, t_vars *vars, int i, int j);
char	*dst(t_data *data, int x, int y);
void	check_space_in_color(char **str);
char	*ft_strjoin(char const *s1, char const *s2);
void	split_ide(t_datta *data);
void	check_map_ide_if_clear(t_datta *data, int i);

#endif