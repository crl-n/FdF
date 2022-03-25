/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:21:23 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/25 21:58:15 by carlnysten       ###   ########.fr       */
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
	if (vars->mlx && vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	if (vars->mlx && vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
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
		ft_putstr(USAGE);
		return (0);
	}
	vars = init_vars();
	if (!vars)
		return (0);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "fdf");
	vars->img = image(vars->mlx);
	vars->menu = image(vars->mlx);
	arr_from_file(argv[1], vars);
	set_color_step(vars);
	center_z_values(vars);
	project(vars->arr, vars);
	draw(vars, vars->arr);
	draw_menu(vars);
	mlx_key_hook(vars->win, key_event, vars);
	mlx_loop(vars->mlx);
	return (0);
}
