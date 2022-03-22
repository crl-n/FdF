/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:29:54 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/13 20:57:23 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			((unsigned char *) dst)[i] = ((const unsigned char *) src)[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len--)
		{
			((unsigned char *) dst)[len] = ((const unsigned char *) src)[len];
		}
	}
	return (dst);
}
