/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:21:56 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/14 22:33:27 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <math.h>

static void	iso(t_point *p)
{
	p->px = (p->x - p->y) * -cos(0.52356);
	p->py = (p->x + p->y) * sin(0.52356) - p->z;
	p->pz = p->z;
}

static void	perspective(t_point *p, t_vars *vars)
{
	double	zn;
	double	zf;

	zn = 1.0;
	zf = 100.0;
	p->px *= vars->ar * vars->fov;
	p->px *= vars->fov;
	p->pz *= (zf + zn) / (zf - zn);
	p->pz *= (2.0 * zn * zf) / (zn - zf);
}

void	project(t_point **arr, t_vars *vars)
{
	int		i;
	t_point	*p;

	i = 0;
	while (i < vars->n_rows * vars->n_cols)
	{
		p = arr[i++];
		if (vars->iso)
			iso(p);
		if (vars->persp)
			perspective(p, vars);
		p->px *= vars->zoom;
		p->py *= vars->zoom;
		p->px += vars->pan_x;
		p->py += vars->pan_y;
	}
}

