/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:21:23 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/07 22:24:19 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h> //remove
#include "fdf.h"

void	die(char *message)
{
	puts(message);
	exit(0);
}

int	**points_from_file(char *filename)
{
	int	fd;
	int	**points;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		die(USAGE);
	points = NULL;
	return (points);
}

int	key_event(int keycode, t_mlx vars)
{
	printf("%#x\n", keycode);
	if (keycode == 0x35)
	{
		mlx_destroy_window(vars.mlx_ptr, vars.window);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	vars;

	(void) argv;
	if (argc != 2)
	{
		puts(USAGE);
		return (0);
	}
	//vars.points = points_from_file(argv[1]);
	vars.mlx_ptr = mlx_init();
	vars.window = mlx_new_window(vars.mlx_ptr, 100, 100, "hello world");
	mlx_key_hook(vars.window, key_event, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
