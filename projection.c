/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:21:56 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/25 20:05:15 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <math.h>

static void	iso(t_point *p, t_vars *vars)
{
	double	theta;

	theta = 0.52356;
	p->px = (p->x - p->y) * cos(theta);
	p->py = (p->x + p->y) * sin(theta) - p->z + vars->z_offset;
	p->pz = p->z;
}

static void	perspective(t_point *p, t_vars *vars)
{
	p->px = p->orig_x;
	p->py = p->orig_y;
	p->pz = p->orig_z;
	p->px *= vars->ar * vars->fov;
	p->py *= vars->fov;
	if (p->z > 0.0)
		p->px *= (p->pz * 0.1);
	if (p->z > 0.0)
		p->py *= (p->pz * 0.1);
	if (p->z < 0.0)
		p->px /= (-p->pz);
	if (p->z < 0.0)
		p->py /= (-p->pz);
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
			iso(p, vars);
		p->px *= vars->zoom;
		p->py *= vars->zoom;
		p->px += vars->pan_x;
		p->py += vars->pan_y;
	}
}
