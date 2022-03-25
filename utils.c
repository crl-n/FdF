/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:28:44 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/25 20:50:15 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"

void	del(void *content, size_t content_size)
{
	(void) content_size;
	if (content)
		free(content);
}

void	center_z_values(t_vars *vars)
{
	size_t	i;
	t_point	*p;

	vars->z_offset = (vars->max_z - vars->min_z) / 2;
	i = 0;
	while (vars->arr[i])
	{
		p = vars->arr[i];
		p->z += vars->z_offset;
		p->orig_x = p->x;
		p->orig_y = p->y;
		p->orig_z = p->z;
		i++;
	}
}
