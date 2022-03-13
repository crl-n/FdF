/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:21:23 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/13 12:59:13 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h> //remove
#include "fdf.h"
#include "libft.h"

void	die(char *message)
{
	ft_putstr(message);
	exit(0);
}

t_point	*new_point(int *coords)
{
	t_point	*point;

	point = (t_point *) malloc(sizeof (t_point));
	if (!point)
		die("Couldn't allocate memory for point.");
	point->y = coords[0];
	point->x = coords[1];
	return (point);
}

// Iterates over 3D vertices, applies projection to each point and
// draws lines between adjacent points.
void	draw(t_vars *vars, int **points)
{
	int		i;
	int		j;
	t_line	*line;

	(void) points;
	i = 0;
	while (i < vars->n_rows)
	{
		j = 0;
		while (j < vars->n_cols)
		{
			if (j > 0)
			{
				line = new_line(j - 1, i, j, i, vars);
				draw_line(vars->mlx, vars->win, line);
			}
			if (i > 0)
			{
				line = new_line(j, i - 1, j, i, vars);
				draw_line(vars->mlx, vars->win, line);
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv) {
	t_vars	*vars;
	int		**points;

	if (argc != 2)
	{
		ft_putstr(USAGE);
		return (0);
	}
	vars = (t_vars *) malloc(sizeof (t_vars));
	points = points_from_file(argv[1], vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "fdf");
	draw(vars, points);
	mlx_key_hook(vars->win, key_event, vars);
	mlx_loop(vars->mlx);
	return (0);
}
