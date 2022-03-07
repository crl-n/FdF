/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:43:25 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/07 22:00:13 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define USAGE "Usage : ./fdf <filename> [ case_size z_size ]\n"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*window;
	int		**points;
} t_mlx;

#endif
