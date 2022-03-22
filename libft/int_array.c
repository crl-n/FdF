/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:22:38 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/22 18:23:36 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

int	**int_array_2d(int n_rows, int n_cols)
{
	int		**arr;
	int		*cells;
	int		i;
	size_t	size;

	size = n_rows * sizeof (int *) + n_cols * sizeof (int);
	arr = (int **) malloc(size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, size);
	cells = (int *)(arr + n_rows);
	i = 0;
	while (i < n_rows)
	{
		arr[i] = cells + i * n_cols;
		i++;
	}
	return (arr);
}
