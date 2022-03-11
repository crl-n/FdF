/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 09:24:35 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/11 15:04:50 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define USAGE "Usage : ./fdf <filename>\n"
# define WIDTH 600
# define HEIGHT 400

typedef struct s_vars
{
	void	*win;
	void	*mlx;
} t_vars;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_img;

typedef struct s_win
{
	void	*window;
	int		width;
	int		height;
} t_win;

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

int		**points_from_file(char *filename, t_vars *vars);
void	draw_line(void *mlx, void *win, t_line *line);
void	die(char *message);
int		key_event(int keycode, t_vars vars); // Should t_vars be t_vars *?

#endif
