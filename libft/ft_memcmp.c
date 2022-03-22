/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:20:26 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/13 20:58:25 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((const unsigned char *) s1)[i] != ((const unsigned char *) s2)[i])
			return (((const unsigned char *) s1)[i]
				- ((const unsigned char *) s2)[i]);
		i++;
	}
	return (0);
}
