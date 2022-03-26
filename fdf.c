/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:21:23 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/26 15:30:24 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"
#include "libft.h"

void	die(char *message, t_vars *vars)
{
	size_t	i;

	ft_putstr(message);
	if (vars->mlx && vars->img->img)
		mlx_destroy_image(vars->mlx, vars->img->img);
	if (vars->img)
		free(vars->img);
	if (vars->mlx && vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->lines)
		ft_lstdel(&(vars->lines), del);
	if (vars->arr)
	{
		i = 0;
		while (vars->arr[i])
			free(vars->arr[i++]);
		free(vars->arr);
	}
	free(vars);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
	{
		if (argc == 1)
			ft_putstr(USAGE);
		else
			ft_putstr("Error: Too many arguments.\n");
		return (0);
	}
	vars = init_vars();
	if (!vars)
		return (0);
	arr_from_file(argv[1], vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "fdf");
	vars->img = image(vars->mlx);
	project(vars->arr, vars);
	draw(vars, vars->arr);
	draw_menu(vars);
	mlx_key_hook(vars->win, key_event, vars);
	mlx_loop(vars->mlx);
	return (0);
}
