/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 09:24:35 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/14 11:34:58 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>
# define USAGE "Usage : ./fdf <filename>\n"
# define WIDTH 600
# define HEIGHT 400

typedef struct s_vars
{
	void	*win;
	void	*mlx;
	int		n_rows;
	int		n_cols;
	double	origin;
	double	max;
	double	min;
	int		scale;
	int		a_ratio;
	int		fov;
} t_vars;

typedef struct s_win
{
	void	*window;
	int		width;
	int		height;
} t_win;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int	color;
}	t_point;

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
void	draw_line(void *mlx, void *win, t_line *line);
void	del(void *content, size_t content_size);
void	die(char *message);
int		key_event(int keycode, t_vars *vars);
t_line	*line(t_point *a, t_point *b, t_vars *vars);
t_point	*point(int x, int y, int z, t_vars *vars);

#endif
