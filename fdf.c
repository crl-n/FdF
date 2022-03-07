/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:21:23 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/07 16:50:22 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

int	key_event(int keycode, t_mlx vars)
{
	(void) keycode;
	mlx_destroy_window(vars.mlx_ptr, vars.window);
	return (0);
}

int	main(void)
{
	t_mlx	vars;

	vars.mlx_ptr = mlx_init();
	vars.window = mlx_new_window(vars.mlx_ptr, 100, 100, "hello world");
	mlx_key_hook(vars.window, key_event, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
