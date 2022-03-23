/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:03:37 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/23 17:27:55 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

static void	refresh(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	project(vars->arr, vars);
	draw(vars, vars->arr);
	draw_menu(vars);
}

static void	adjust_fov(t_vars *vars, int keycode)
{
	if (vars->fov < 5.0 && keycode == 0x20)
		vars->fov += 0.1 / tan(1.0 / 2.0);
	if (vars->fov > 0.0 && keycode == 0x22)
		vars->fov -= 0.1 / tan(1.0 / 2.0);
}

static void	esc(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_event(int keycode, t_vars *vars)
{
	printf("keyc %#x\n", keycode);
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
	else if (keycode == KEY_G || keycode == KEY_H)
		adjust_fov(vars, keycode);
	else if (is_rot_key(keycode))
		rotate(vars->arr, keycode);
	refresh(vars);
	return (0);
}
