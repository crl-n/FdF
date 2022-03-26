/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:14:59 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/26 17:31:26 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "fdf.h"

static void	gentle_slope(t_vars *vars, t_line *line)
{
	double	threshold;
	double	offset;
	int		x;
	int		y;
	double	z;

	threshold = 0.5;
	offset = 0.0;
	x = line->x0;
	y = line->y0;
	z = line->z0;
	while (x != line->x1)
	{
		put_pxl(vars->img, x, y, get_color(z, vars));
		x += line->sx;
		if (line->dz != 0.0 && line->dx != 0.0)
			z += line->sz * (line->dz / line->dx);
		offset += fabs(line->m);
		if (offset > threshold)
		{
			y += line->sy;
			threshold += 1.0;
		}
	}
	put_pxl(vars->img, line->x1, line->y1, get_color(z, vars));
}

static void	steep_slope(t_vars *vars, t_line *line)
{
	double	threshold;
	double	offset;
	int		x;
	int		y;
	double	z;

	threshold = 0.5;
	offset = 0.0;
	x = line->x0;
	y = line->y0;
	z = line->z0;
	while (y != line->y1)
	{
		put_pxl(vars->img, x, y, get_color(z, vars));
		y += line->sy;
		if (line->dz != 0.0 && line->dy != 0.0)
			z += line->sz * (line->dz / line->dy);
		offset += fabs(1 / line->m);
		if (offset > threshold)
		{
			x += line->sx;
			threshold += 1.0;
		}
	}
	put_pxl(vars->img, line->x1, line->y1, get_color(z, vars));
}

static void	vertical_line(t_vars *vars, t_line *line)
{
	int		x;
	int		y;
	double	z;

	x = line->x0;
	y = line->y0;
	z = line->z0;
	while (y != line->y1)
	{
		put_pxl(vars->img, x, y, get_color(z, vars));
		if (line->dz != 0.0 && line->dx != 0.0)
			z += line->sz * (line->dz / line->dy);
		y += line->sy;
	}
}

// line equation: mx + b
void	draw_line(t_line *line, t_vars *vars)
{
	if (!line)
		die("Error: NULL line in draw_line().\n", vars);
	if (line->dx == 0)
		vertical_line(vars, line);
	else if (line->m < 1 && line->m > -1)
		gentle_slope(vars, line);
	else
		steep_slope(vars, line);
	free(line);
}
