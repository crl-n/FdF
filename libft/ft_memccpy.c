/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:20:54 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/13 20:59:08 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *) dst)[i] = ((const unsigned char *) src)[i];
		if (((const unsigned char *) src)[i] == (unsigned char) c)
			return (dst + i + 1);
		i++;
	}
	return ((void *) 0);
}
