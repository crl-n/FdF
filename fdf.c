/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:21:23 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/14 11:44:19 by carlnysten       ###   ########.fr       */
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

	p = (t_point *) malloc(sizeof (t_point));
	if (!p)
		die("Couldn't allocate memory for point.");
	p->x = (x - y) * cos(0.52356);
	p->y = (x + y) * sin(0.52356) - z * 0.4;
	p->z = z;
	if (p->x > vars->max)
		vars->max = p->x;
	if (p->y > vars->max)
		vars->max = p->y;
	if (p->x < vars->min)
		vars->min = p->x;
	if (p->y < vars->min)
		vars->min = p->y;
	//printf("o %f max %f\n", vars->origin, vars->max);
	//printf("%d %d %d\n", x, y, z);
	//printf("%f %f %f\n", nx, ny, nz);
	//printf("%f %f %f\n", p->x, p->y, p->z);
	return (p);
}

// Iterates over 3D vertices, applies projection to each point and
// draws lines between adjacent points.
void	draw(t_vars *vars, t_point **arr)
{
	int		i;
	int		j;
	t_line	*l;

	i = 0;
	while (i < vars->n_rows)
	{
		j = 0;
		while (j < vars->n_cols)
		{
			if (j > 0)
			{
				l = line(arr[i * vars->n_cols + j - 1], arr[i * vars->n_cols + j], vars);
				draw_line(vars->mlx, vars->win, l);
			}
			if (i > 0)
			{
				l = line(arr[(i - 1) * vars->n_cols + j], arr[i * vars->n_cols + j], vars);
				draw_line(vars->mlx, vars->win, l);
			}
			j++;
		}
		i++;
	}
}

void	normalise_arr(t_point **arr, t_vars *vars)
{
	int	i;

	vars->origin = (vars->max - vars->min) / 2.0;
	printf("min %f max %f origin %f \n", vars->min, vars->max, vars->origin);
	i = 0;
	while (i < vars->n_rows * vars->n_cols)
	{
		arr[i]->x = normalise(-vars->min + arr[i]->x, vars);
		arr[i]->y = normalise(-vars->min + arr[i]->y, vars);
		printf("%f %f\n", arr[i]->x, arr[i]->y);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_vars	*vars;
	t_point	**arr;

	if (argc != 2)
	{
		ft_putstr(USAGE);
		return (0);
	}
	vars = (t_vars *) malloc(sizeof (t_vars));
	arr = arr_from_file(argv[1], vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "fdf");
	normalise_arr(arr, vars);
	draw(vars, arr);
	mlx_key_hook(vars->win, key_event, vars);
	mlx_loop(vars->mlx);
	return (0);
}
