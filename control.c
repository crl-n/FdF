/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:03:37 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/22 18:25:19 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

static void	refresh(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	project(vars->arr, vars);
	draw(vars, vars->arr);
}

int	key_event(int keycode, t_vars *vars)
{
	if (keycode == 0x35)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
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
	refresh(vars);
	return (0);
}
