/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:21:23 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/13 23:37:38 by carlnysten       ###   ########.fr       */
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

double	normalise(double value, t_vars *vars)
{
	if (value < vars->origin)
		return (((double) vars->origin - value) / vars->origin * -1.0);
	return ((value - (double) vars->origin) / vars->origin);
}

t_point	*point(int x, int y, int z, t_vars *vars)
{
	t_point	*p;
	double	nx;
	double	ny;
	double	nz;

	p = (t_point *) malloc(sizeof (t_point));
	if (!p)
		die("Couldn't allocate memory for point.");
	nx = normalise(x, vars);
	ny = normalise(y, vars);
	nz = normalise(z, vars);
	p->x = (nx - ny) * cos(0.52356);
	p->y = (nx + ny) * sin(0.52356) - nz * 0.4;
	p->z = nz;
	printf("%d\n", vars->origin);
	printf("%d %d %d\n", x, y, z);
	printf("%f %f %f\n", nx, ny, nz);
	printf("%f %f %f\n", p->x, p->y, p->z);
	return (p);
}

// Iterates over 3D vertices, applies projection to each point and
// draws lines between adjacent points.
void	draw(t_vars *vars, int **arr)
{
	int		i;
	int		j;
	t_line	*l;

	(void) arr;
	i = 0;
	while (i < vars->n_rows)
	{
		j = 0;
		while (j < vars->n_cols)
		{
			if (j > 0)
			{
				l = line(point(j - 1, i, arr[i][j - 1], vars), point(j, i, arr[i][j], vars), vars);
				draw_line(vars->mlx, vars->win, l);
			}
			if (i > 0)
			{
				l = line(point(j, i - 1, arr[i - 1][j], vars), point(j, i, arr[i][j], vars), vars);
				draw_line(vars->mlx, vars->win, l);
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_vars	*vars;
	int		**arr;

	if (argc != 2)
	{
		ft_putstr(USAGE);
		return (0);
	}
	vars = (t_vars *) malloc(sizeof (t_vars));
	arr = arr_from_file(argv[1], vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "fdf");
	draw(vars, arr);
	mlx_key_hook(vars->win, key_event, vars);
	mlx_loop(vars->mlx);
	return (0);
}
