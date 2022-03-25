/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:03:37 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/25 22:06:11 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>

static void	refresh(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	project(vars->arr, vars);
	draw(vars, vars->arr);
	draw_menu(vars);
}

static void	adjust_fov(t_vars *vars, int key)
{
	if (vars->fov < 5.0 && key == KEY_G)
		vars->fov += 0.1 / tan(1.0 / 2.0);
	if (vars->fov > 0.0 && key == KEY_H)
		vars->fov -= 0.1 / tan(1.0 / 2.0);
}

static void	adjust_pan(t_vars *vars, int key)
{
	if (key == 0xd)
		vars->pan_y -= 10.0;
	else if (key == 0x1)
		vars->pan_y += 10.0;
	else if (key == 0x0)
		vars->pan_x -= 10.0;
	else if (key == 0x2)
		vars->pan_x += 10.0;
}

int	key_event(int key, t_vars *vars)
{
	if (key == 0x35)
		die("", vars);
	if (key == 0x26 && vars->zoom > 1.0)
		vars->zoom--;
	else if (key == 0x28 && vars->zoom < 100.0)
		vars->zoom++;
	else if (key == 0xd || key == 0x1 || key == 0x0 || key == 0x2)
		adjust_pan(vars, key);
	else if (key == 0xf)
		vars->persp = vars->persp ^ 1;
	else if (key == KEY_G || key == KEY_H)
		adjust_fov(vars, key);
	else if (is_rot_key(key))
		rotate(vars->arr, key);
	else if (key == 0xc)
		vars->color = vars->color ^ 1;
	refresh(vars);
	return (0);
}
