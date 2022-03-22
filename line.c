/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:39:14 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/22 18:40:40 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <math.h>

t_line	*line(t_point *a, t_point *b)
{
	t_line	*line;

	line = (t_line *) malloc(sizeof (t_line));
	if (!line)
		return (NULL);
	line->x0 = a->px;
	line->y0 = a->py;
	line->x1 = b->px;
	line->y1 = b->py;
	line->dx = fabs((double) line->x1 - (double) line->x0);
	line->dy = fabs((double) line->y1 - (double) line->y0);
	line->sx = 1;
	line->sy = 1;
	if (line->x0 > line->x1)
		line->sx = -1;
	if (line->y0 > line->y1)
		line->sy = -1;
	if (line->dx != 0.0)
		line->m = (double) line->dy / line->dx;
	return (line);
}
