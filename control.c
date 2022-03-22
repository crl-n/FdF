/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:03:37 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/23 00:35:49 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>
#include <math.h>

static void	refresh(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	project(vars->arr, vars);
	draw(vars, vars->arr);
	draw_menu(vars);
}

static void	increase_fov(t_vars *vars)
{
	if (vars->fov < 5.0)
		vars->fov += 0.1 / tan(1.0 / 2.0);
}

static void	decrease_fov(t_vars *vars)
{
	if (vars->fov > 0.0)
		vars->fov -= 0.1 / tan(1.0 / 2.0);
}

static void	esc(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_event(int keycode, t_vars *vars)
{
	if (keycode == 0x35)
		esc(vars);
	if (keycode == 0x26)
		vars->zoom--;
	else if (keycode == 0x28)
		vars->zoom++;
	else if (keycode == 0xd)
		vars->pan_y -= 10;
	else if (keycode == 0x1)
		vars->pan_y += 10;
	else if (keycode == 0x0)
		vars->pan_x -= 10;
	else if (keycode == 0x2)
		vars->pan_x += 10;
	else if (keycode == 0xf && vars->persp)
		vars->persp = 0;
	else if (keycode == 0xf && !vars->persp)
		vars->persp = 1;
	else if (keycode == 0x20)
		increase_fov(vars);
	else if (keycode == 0x22)
		decrease_fov(vars);
	refresh(vars);
	return (0);
}
