/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:21:56 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/23 13:14:20 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <math.h>

#include <stdio.h>

static void	iso(t_point *p)
{
	p->px = (p->x - p->y) * -cos(0.52356);
	p->py = (p->x + p->y) * sin(0.52356) - p->z;
	p->pz = p->z;
}

static double	norm(double v)
{
	double	nv;
	double	origin;

	origin = (double)(WIDTH / 2 - 1);
	nv = (v - origin) / origin;
	return (nv);
}

static double	denorm(double nv)
{
	double	v;
	double	origin;

	printf("nv %f ", nv);
	origin = (double)(WIDTH / 2 - 1);
	v = nv * origin + origin;
	printf("v: %f\n", v);
	return (v);
}

static void	perspective(t_point *p, t_vars *vars)
{
	double	zn;
	double	zf;

	zn = norm(20.0);
	zf = norm(1000.0);
	p->px = norm(p->x);
	p->py = norm(p->y);
	p->pz = norm(p->z);
	p->px *= vars->ar * vars->fov;
	if (p->z != 0.0)
		p->px /= fabs(norm(p->z));
	p->py *= vars->fov;
	if (p->z != 0.0)
		p->py /= fabs(norm(p->z));
	p->pz *= (zf + zn) / (zf - zn);
	p->pz *= (2.0 * zn * zf) / (zn - zf);
	printf("x ");
	p->px = denorm(p->px);
	printf("y ");
	p->py = denorm(p->py);
	printf("z ");
	p->pz = denorm(p->pz);
}

void	project(t_point **arr, t_vars *vars)
{
	int		i;
	t_point	*p;

	i = 0;
	while (i < vars->n_rows * vars->n_cols)
	{
		p = arr[i++];
		if (vars->persp)
			perspective(p, vars);
		else
			iso(p);
		p->px *= vars->zoom;
		p->py *= vars->zoom;
		p->px += vars->pan_x;
		p->py += vars->pan_y;
	}
}
