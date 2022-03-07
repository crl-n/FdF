/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:21:23 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/07 14:55:09 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int	main(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	mlx_new_window(mlx_ptr, 100, 100, "hello world");
	return (0);
}
