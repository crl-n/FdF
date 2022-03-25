/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:51:04 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/25 19:10:49 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	rotate_x(t_point **arr, double theta)
{
	double	y;
	double	z;
	size_t	i;
	t_point	*p;

	i = 0;
	while (arr[i])
	{
		p = arr[i];
		y = p->y;
		z = p->z;
		p->y = y * cos(theta) - z * sin(theta);
		p->z = y * sin(theta) + z * cos(theta);
		i++;
	}
}

static void	rotate_y(t_point **arr, double theta)
{
	double	x;
	double	z;
	size_t	i;
	t_point	*p;

	i = 0;
	while (arr[i])
	{
		p = arr[i];
		x = p->x;
		z = p->z;
		p->x = x * cos(theta) + z * sin(theta);
		p->z = x * -sin(theta) + z * cos(theta);
		i++;
	}
}

static void	rotate_z(t_point **arr, double theta)
{
	double	x;
	double	y;
	size_t	i;
	t_point	*p;

	i = 0;
	while (arr[i])
	{
		p = arr[i];
		x = p->x;
		y = p->y;
		p->x = x * cos(theta) + y * -sin(theta);
		p->y = x * sin(theta) + y * cos(theta);
		i++;
	}
}

void	rotate(t_point **arr, int keycode)
{
	if (keycode == KEY_T)
		rotate_x(arr, ROT_THETA);
	else if (keycode == KEY_Y)
		rotate_x(arr, -ROT_THETA);
	else if (keycode == KEY_U)
		rotate_y(arr, ROT_THETA);
	else if (keycode == KEY_I)
		rotate_y(arr, -ROT_THETA);
	else if (keycode == KEY_O)
		rotate_z(arr, ROT_THETA);
	else if (keycode == KEY_P)
		rotate_z(arr, -ROT_THETA);
}
