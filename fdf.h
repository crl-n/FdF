/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:43:25 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/08 19:21:00 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define USAGE "Usage : ./fdf <filename> [ case_size z_size ]\n"
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

#endif
