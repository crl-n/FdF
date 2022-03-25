/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:08:43 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/25 20:31:47 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color_step(t_vars *vars)
{
	vars->step_z = 0.5 + (vars->max_z - vars->min_z) / 15.0;
}

int	get_color(double z, t_vars *vars)
{
	double	i;
	int		color;

	if (!vars->color)
		return (0xFFFFFF);
	i = vars->min_z + vars->z_offset;
	color = 0xFFFFFF;
	while (i <= z)
	{
		color -= 0x1111;
		i += vars->step_z;
	}
	return (color);
}
