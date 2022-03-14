/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:21:23 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/14 22:21:49 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h> //remove
#include <math.h>
#include "fdf.h"
#include "libft.h"

void	die(char *message)
{
	ft_putstr(message);
	exit(0);
}

t_point	*point(int x, int y, int z, t_vars *vars)
{
	t_point	*p;

	p = (t_point *) malloc(sizeof (t_point));
	if (!p)
		die("Couldn't allocate memory for point.");
	p->x = (double) x;
	p->y = (double) y;
	p->z = (double) z;
	if (p->z > vars->max_z)
		vars->max_z = p->z;
	if (p->z < vars->min_z)
		vars->min_z = p->z;
	return (p);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
	{
		ft_putstr(USAGE);
		return (0);
	}
	vars = (t_vars *) malloc(sizeof (t_vars));
	vars->arr = arr_from_file(argv[1], vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "fdf");
	vars->iso = 1;
	vars->persp = 1;
	vars->fov = 1.0 / tan(1.0 / 2.0);
	vars->ar = WIDTH / HEIGHT;
	vars->zoom = 10.0;
	vars->pan_x = (double) WIDTH / 2.0;
	vars->pan_y = (double) HEIGHT / 2.0;
	project(vars->arr, vars);
	draw(vars, vars->arr);
	mlx_key_hook(vars->win, key_event, vars);
	mlx_loop(vars->mlx);
	return (0);
}
