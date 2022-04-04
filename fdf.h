/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 09:24:35 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/26 16:28:40 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>
# include "libft.h"

# define USAGE "Usage : ./fdf <filename>\n"
# define WIDTH 1080
# define HEIGHT 720
# define ROT_THETA 0.1
# define KEY_T 0x11
# define KEY_Y 0x10
# define KEY_U 0x20
# define KEY_I 0x22
# define KEY_O 0x1f
# define KEY_P 0x23
# define KEY_G 0x5
# define KEY_H 0x4

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	double	orig_x;
	double	orig_y;
	double	orig_z;
	double	px;
	double	py;
	double	pz;
	int		color;
}	t_point;

typedef struct s_img
{
	void	*img;
	char	*data;
	int		bpp;
	int		lb;
	int		end;
}	t_img;

typedef struct s_vars
{
	void	*win;
	void	*mlx;
	t_img	*img;
	t_point	**arr;
	t_list	*lines;
	int		iso : 1;
	int		persp;
	int		color;
	int		n_rows;
	int		n_cols;
	double	max_z;
	double	min_z;
	double	z_offset;
	double	step_z;
	double	fov;
	double	fov_theta;
	double	ar;
	double	zoom;
	double	pan_x;
	double	pan_y;
}	t_vars;

typedef struct s_line
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	double	z0;
	double	z1;
	double	dx;
	double	dy;
	double	dz;
	int		sx;
	int		sy;
	double	sz;
	double	m;
}	t_line;

void	arr_from_file(char *filename, t_vars *vars);
void	center_z_values(t_vars *vars);
void	clear_img(t_img *img);
void	del(void *content, size_t content_size);
double	deg_to_rad(double deg);
void	die(char *message, t_vars *vars);
void	draw(t_vars *vars, t_point **arr);
void	draw_line(t_line *line, t_vars *vars);
void	draw_menu(t_vars *vars);
void	free_split(char ***adr);
int		get_color(double z, t_vars *vars);
t_img	*image(void *img);
t_vars	*init_vars(void);
int		is_rot_key(int keycode);
int		key_event(int keycode, t_vars *vars);
t_line	*line(t_point *a, t_point *b, t_line *line);
t_point	*point(int x, int y, int z, t_vars *vars);
t_point	**point_array(int n_rows, int n_cols);
void	project(t_point **arr, t_vars *vars);
void	put_pxl(t_img *img, int x, int y, int color);
void	rotate(t_point **arr, int keycode);
void	set_color_step(t_vars *vars);

#endif
