/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:21:23 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/11 15:03:28 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h> //remove
#include <fcntl.h>
#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

void	die(char *message)
{
	ft_putstr(message);
	exit(0);
}

int	main(int argc, char **argv) {
	t_vars	vars;
	t_win	win;
	int		**points;

	(void) points;
	if (argc != 2)
	{
		ft_putstr(USAGE);
		return (0);
	}
	points = points_from_file(argv[1], &vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fdf");
	win.width = WIDTH;
	win.height = HEIGHT;
	vars.win = &win;
	mlx_key_hook(vars.win, key_event, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
