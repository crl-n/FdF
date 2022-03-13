/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:14:59 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/13 23:29:09 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "fdf.h"

// line equation: mx + b
//TODO Split up into several functions and norm fix
void	draw_line(void *mlx, void *win, t_line *line)
{
	double	threshold = 0.5;
	double	offset = 0.0;
	int x = line->x0;
	int y = line->y0;

	//TODO: If dx == 0
	if (line->m < 1 && line->m > -1)
	{
		while (x != line->x1)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
			x += line->sx;
			offset += fabs(line->m);
			if (offset > threshold)
			{
				y += line->sy;
				threshold += 1.0;
			}
		}
	}
	else
	{
		while (y != line->y1)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
			y += line->sy;
			offset += fabs(1/line->m);
			if (offset > threshold)
			{
				x += line->sx;
				threshold += 1.0;
			}
		}
	}
	free(line);
}

int	denormalise(double value, t_vars *vars)
{
	(void) vars;
	return ((int)(HEIGHT / 2 + value * HEIGHT / 2));
}


t_line	*line(t_point *a, t_point * b, t_vars *vars)
{
	t_line	*line;

	(void) vars;
	line = (t_line *) malloc(sizeof (t_line));
	if (!line)
		return (NULL);
	line->x0 = denormalise(a->x, vars);
	line->y0 = denormalise(a->y, vars);
	line->x1 = denormalise(b->x, vars);
	line->y1 = denormalise(b->y, vars);
	line->dx = fabs((double) line->x1 - (double) line->x0);
	line->dy = fabs((double) line->y1 - (double) line->y0);
	line->sx = 1;
	line->sy = 1;
	if (line->x0 > line->x1)
		line->sx = -1;
	if (line->y0 > line->y1)
		line->sy = -1;
	line->m = (double) line->dy / line->dx; //TODO: division by zero
	free(a);
	free(b);
	return (line);
}
