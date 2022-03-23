/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:13:48 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/23 17:25:42 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_rot_key(int keycode)
{
	if (keycode == KEY_T || keycode == KEY_Y)
		return (1);
	if (keycode == KEY_U || keycode == KEY_I)
		return (1);
	if (keycode == KEY_O || keycode == KEY_P)
		return (1);
	return (0);
}
