/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:39:14 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/25 14:12:12 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdlib.h>
#include <math.h>
#include "libft.h"

t_img	*image(void *mlx)
{
	t_img	*img;

	img = (t_img *) malloc(sizeof (t_img));
	if (!img)
		return (NULL);
	ft_bzero(img, sizeof (t_img));
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->lb, &img->end);
	return (img);
}

t_point	*point(int x, int y, int z, t_vars *vars)
{
	t_point	*p;

	(void) vars;
	p = (t_point *) malloc(sizeof (t_point));
	if (!p)
		die("Couldn't allocate memory for point.");
	ft_bzero(p, sizeof (t_point));
	p->x = (double) x;
	p->y = (double) y;
	p->z = (double) z;
	p->orig_x = (double) x;
	p->orig_y = (double) y;
	p->orig_z = (double) z;
	return (p);
}

t_vars	*init_vars(void)
{
	t_vars	*vars;

	vars = (t_vars *) malloc(sizeof (t_vars));
	if (!vars)
		return (NULL);
	ft_bzero(vars, sizeof (t_vars));
	vars->iso = 1;
	vars->persp = 0;
	vars->fov = 1.0 / tan(1.0 / 2.0);
	vars->ar = WIDTH / HEIGHT;
	vars->zoom = 10.0;
	vars->pan_x = (double) WIDTH / 2.0;
	vars->pan_y = (double) HEIGHT / 2.0;
	vars->max_z = -2147483648.0;
	vars->min_z = 2147483647.0;
	return (vars);
}

t_line	*line(t_point *a, t_point *b)
{
	t_line	*line;

	line = (t_line *) malloc(sizeof (t_line));
	if (!line)
		return (NULL);
	line->x0 = a->px;
	line->y0 = a->py;
	line->x1 = b->px;
	line->y1 = b->py;
	line->z0 = a->orig_z;
	line->z1 = b->orig_z;
	line->dx = fabs((double) line->x1 - (double) line->x0);
	line->dy = fabs((double) line->y1 - (double) line->y0);
	line->dz = fabs(line->z1 - line->z0);
	line->sx = 1;
	line->sy = 1;
	line->sz = 1;
	if (line->x0 > line->x1)
		line->sx = -1;
	if (line->y0 > line->y1)
		line->sy = -1;
	if (line->z0 > line->z1)
		line->sz = -1;
	if (line->dx != 0.0)
		line->m = (double) line->dy / line->dx;
	return (line);
}
