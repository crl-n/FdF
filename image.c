/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:41:16 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/22 23:12:05 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	put_pxl(int x, int y, int color)
{
	int	pxl;

	pxl = (y * img->lb) + (x * 4);
	if (img->end == 1)
	{
		img->data[pxl] = color;
		img->data[pxl + 1] = (color >> 24) & 0xFF;
		img->data[pxl + 2] = (color >> 16) & 0xFF;
		img->data[pxl + 3] = (color >> 8) & 0xFF;
	}
	else
	{
		img->data[pxl] = color;
		img->data[pxl + 1] = (color >> 24) & 0xFF;
		img->data[pxl + 2] = (color >> 16) & 0xFF;
		img->data[pxl + 3] = (color >> 8) & 0xFF;
	}
}
