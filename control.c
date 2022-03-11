/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:03:37 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/11 15:04:18 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

int	key_event(int keycode, t_vars vars) // Should t_vars be t_vars *?
{
	//printf("%#x\n", keycode);
	if (keycode == 0x35)
	{
		mlx_destroy_window(vars.mlx, vars.win);
		exit(0);
	}
	return (0);
}

