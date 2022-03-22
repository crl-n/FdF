/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:09:17 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/23 00:31:32 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	draw_menu(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 20, 30, 0xCC00CC, "Controls");
	mlx_string_put(vars->mlx, vars->win, 20, 60, 0xAA00AA, "Zoom: J/K");
	mlx_string_put(vars->mlx, vars->win, 20, 90, 0xAA00AA, "Pan: W/A/S/D");
	mlx_string_put(vars->mlx, vars->win, 20, 120, 0xAA00AA, "FOV: U/I");
	mlx_string_put(vars->mlx, vars->win, 20, 150, 0xAA00AA, "Quit: ESC");
}
