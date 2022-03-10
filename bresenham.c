#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "fdf.h"

// line equation: mx + b
//TODO Split up into several functions and norm fix
void	draw_line(void *mlx, void *win, t_line *line)
{
	double	threshold = 0.5;
	double	offset = 0.0;
	int x = line->x0;
	int y = line->y0;

	//TODO: If dx == 0
	if (line->m < 1 && line->m > -1)
	{
		while (x != line->x1)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
			x += line->sx;
			offset += fabs(line->m);
			if (offset > threshold)
			{
				y += line->sy;
				threshold += 1.0;
			}
		}
	}
	else
	{
		while (y != line->y1)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
			y += line->sy;
			offset += fabs(1/line->m);
			if (offset > threshold)
			{
				x += line->sx;
				threshold += 1.0;
			}
		}
	}
	free(line);
}

t_line	*new_line(int x0, int y0, int x1, int y1)
{
	t_line	*line;

	line = (t_line *) malloc(sizeof (t_line));
	if (!line)
		return (NULL);
	line->x0 = x0;
	line->y0 = y0;
	line->x1 = x1;
	line->y1 = y1;
	line->dx = fabs((double) x1 - (double) x0);
	line->dy = fabs((double) y1 - (double) y0);
	line->sx = 1;
	line->sy = 1;
	if (x0 > x1)
		line->sx = -1;
	if (y0 > y1)
		line->sy = -1;
	line->m = (double) line->dy / line->dx; //TODO: division by zero
	return (line);
}
