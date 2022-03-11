/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:21:23 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/11 18:27:33 by carlnysten       ###   ########.fr       */
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

void	draw(t_vars *vars, int **points)
{
	int		i;
	int		j;
	t_line	*line;

	(void) points;
	i = 0;
	while (i < vars->n_rows)
	{
		j = 1;
		while (j < vars->n_cols)
		{
			line = new_line(j - 1, i, j, i);
			draw_line(vars->mlx, vars->win, line);
			j++;
		}
		i++;
	}
	i = 1;
	while (i < vars->n_rows)
	{
		j = 0;
		while (j < vars->n_cols)
		{
			line = new_line(j, i - 1, j, i);
			draw_line(vars->mlx, vars->win, line);
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
