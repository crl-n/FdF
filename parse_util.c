/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:28:44 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/25 14:27:03 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"

void	del(void *content, size_t content_size)
{
	(void) content_size;
	free(content);
}

t_point	**point_array(int n_rows, int n_cols)
{
	t_point	**arr;
	size_t	size;

	size = (n_rows * n_cols + 1) * sizeof (t_point **);
	arr = (t_point **) malloc(size);
	if (!arr)
		die("Malloc fail.");
	ft_bzero(arr, size);
	return (arr);
}

void	center_z_values(t_vars *vars)
{
	size_t	i;

	vars->z_offset = (vars->max_z - vars->min_z) / 2;
	i = 0;
	while (vars->arr[i])
	{
		t_point *p = vars->arr[i];
		p->z += vars->z_offset;
		p->orig_x = p->x;
		p->orig_y = p->y;
		p->orig_z = p->z;
		i++;
	}
}
