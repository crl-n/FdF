/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:09:17 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/25 22:00:48 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	draw_menu(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 20, 30, 0xCC00CC, "Controls");
	mlx_string_put(vars->mlx, vars->win, 20, 60, 0xAA00AA, "Zoom: J/K");
	mlx_string_put(vars->mlx, vars->win, 20, 90, 0xAA00AA, "Pan: W/A/S/D");
	mlx_string_put(vars->mlx, vars->win, 20, 120, 0xAA00AA, "Rotate X: T/Y");
	mlx_string_put(vars->mlx, vars->win, 20, 150, 0xAA00AA, "Rotate Y: U/I");
	mlx_string_put(vars->mlx, vars->win, 20, 180, 0xAA00AA, "Rotate Z: O/P");
	mlx_string_put(vars->mlx, vars->win, 20, 210, 0xAA00AA, "FOV: G/H");
	mlx_string_put(vars->mlx, vars->win, 20, 240, 0xAA00AA, "Projection: R");
	mlx_string_put(vars->mlx, vars->win, 20, 270, 0xAA00AA, "Color: Q");
	mlx_string_put(vars->mlx, vars->win, 20, 300, 0xAA00AA, "Quit: ESC");
}
