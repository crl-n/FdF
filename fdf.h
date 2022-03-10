/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:43:25 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/10 09:18:47 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define USAGE "Usage : ./fdf <filename> [ case_size z_size ]\n"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*window;
	int		**points;
} t_mlx;

typedef struct s_vars
{
	int	x;
	int	y;
	void	*mlx;
	void	*win;
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

#endif
