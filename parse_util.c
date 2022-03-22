/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:28:44 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/22 18:46:05 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"

void	del(void *content, size_t content_size)
{
	(void) content_size;
	free(content);
}

t_point	**point_array(int n_rows, int n_cols)
{
	t_point	**arr;
	size_t	size;

	size = n_rows * n_cols * sizeof (t_point **);
	arr = (t_point **) malloc(size);
	if (!arr)
		die("Malloc fail.");
	ft_bzero(arr, size);
	return (arr);
}
