/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:14:59 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/22 18:50:49 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "fdf.h"
#include <stdio.h>

static void	gentle_slope(t_vars *vars, t_line *line)
{
	double	threshold;
	double	offset;
	int		x;
	int		y;

	printf("gentle");
	threshold = 0.5;
	offset = 0.0;
	x = line->x0;
	y = line->y0;
	while (x != line->x1)
	{
		mlx_pixel_put(vars->mlx, vars->win, x, y, 0xFFFFFF);
		x += line->sx;
		offset += fabs(line->m);
		if (offset > threshold)
		{
			y += line->sy;
			threshold += 1.0;
		}
	}
	mlx_pixel_put(vars->mlx, vars->win, line->x1, line->y1, 0xFFFFFF);
}

static void	steep_slope(t_vars *vars, t_line *line)
{
	double	threshold;
	double	offset;
	int		x;
	int		y;

	printf("steep");
	threshold = 0.5;
	offset = 0.0;
	x = line->x0;
	y = line->y0;
	while (y != line->y1)
	{
		mlx_pixel_put(vars->mlx, vars->win, x, y, 0xFFFFFF);
		y += line->sy;
		offset += fabs(1 / line->m);
		if (offset > threshold)
		{
			x += line->sx;
			threshold += 1.0;
		}
	}
	mlx_pixel_put(vars->mlx, vars->win, line->x1, line->y1, 0xFFFFFF);
}

static void	vertical_line(t_vars *vars, t_line *line)
{
	int		x;
	int		y;

	printf("vertical");
	x = line->x0;
	y = line->y0;
	while (y != line->y1)
	{
		mlx_pixel_put(vars->mlx, vars->win, x, y, 0xFFFFFF);
		y += line->sy;
	}
}

// line equation: mx + b
void	draw_line(t_line *line, t_vars *vars)
{
	if (line->dx == 0)
		vertical_line(vars, line);
	else if (line->m < 1 && line->m > -1)
		gentle_slope(vars, line);
	else
		steep_slope(vars, line);
	free(line);
}
