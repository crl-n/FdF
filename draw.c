/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:27:36 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/22 18:47:13 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

// Iterates over 3D vertices, applies projection to each point and
// draws lines between adjacent points.
void	draw(t_vars *vars, t_point **arr)
{
	int		i;
	int		j;

	i = 0;
	while (i < vars->n_rows)
	{
		j = 0;
		while (j < vars->n_cols)
		{
			if (j > 0)
				draw_line(line(arr[i * vars->n_cols + j - 1],
						arr[i * vars->n_cols + j]), vars);
			if (i > 0)
				draw_line(line(arr[(i - 1) * vars->n_cols + j],
						arr[i * vars->n_cols + j]), vars);
			j++;
		}
		i++;
	}
}
