/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:27:36 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/14 21:28:16 by carlnysten       ###   ########.fr       */
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
	t_line	*l;

	i = 0;
	while (i < vars->n_rows)
	{
		j = 0;
		while (j < vars->n_cols)
		{
			if (j > 0)
			{
				l = line(arr[i * vars->n_cols + j - 1], arr[i * vars->n_cols + j], vars);
				draw_line(l, vars);
			}
			if (i > 0)
			{
				l = line(arr[(i - 1) * vars->n_cols + j], arr[i * vars->n_cols + j], vars);
				draw_line(l, vars);
			}
			j++;
		}
		i++;
	}
}

