/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 09:24:35 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/22 23:45:03 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>
# define USAGE "Usage : ./fdf <filename>\n"
# define WIDTH 1080
# define HEIGHT 720

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
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
	int		iso : 1;
	int		persp : 1;
	int		n_rows;
	int		n_cols;
	double	max_z;
	double	min_z;
	double	fov;
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
	double	dx;
	double	dy;
	int		sx;
	int		sy;
	double	m;
}	t_line;

t_point	**arr_from_file(char *filename, t_vars *vars);
void	clear_img(t_img *img);
void	del(void *content, size_t content_size);
void	die(char *message);
void	draw(t_vars *vars, t_point **arr);
void	draw_line(t_line *line, t_vars *vars);
t_img	*image(void *img);
t_vars	*init_vars(void);
int		key_event(int keycode, t_vars *vars);
t_line	*line(t_point *a, t_point *b);
t_point	*point(int x, int y, int z, t_vars *vars);
t_point	**point_array(int n_rows, int n_cols);
void	project(t_point **arr, t_vars *vars);
void	put_pxl(t_img *img, int x, int y, int color);

#endif
