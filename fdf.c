/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:21:23 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/13 20:36:55 by carlnysten       ###   ########.fr       */
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

t_point	*point(int x, int y, int z)
{
	t_point	*p;

	x *= 10;
	y *= 10;
	z *= 10;
	p = (t_point *) malloc(sizeof (t_point));
	if (!p)
		die("Couldn't allocate memory for point.");
	p->x = (x - y) * cos(0.52356);
	p->y = - z + (x + y) * sin(0.52356);
	p->z = z;
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
				l = line(point(j - 1, i, arr[i][j - 1]), point(j, i, arr[i][j]), vars);
				draw_line(vars->mlx, vars->win, l);
			}
			if (i > 0)
			{
				l = line(point(j, i - 1, arr[i - 1][j]), point(j, i, arr[i][j]), vars);
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
