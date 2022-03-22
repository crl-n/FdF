/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:57:15 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/22 19:29:17 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static int	handle_negative(int n, int *sign)
{
	if (n < 0)
	{
		*sign = -1;
		n = -n;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	size;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_intlen(n) + 1;
	sign = 1;
	n = handle_negative(n, &sign);
	s = (char *) malloc(size * sizeof (char));
	if (!s)
		return (NULL);
	s[--size] = '\0';
	while (size > 0)
	{
		s[--size] = '0' + (n % 10);
		n = n / 10;
	}
	if (sign == -1)
		s[0] = '-';
	return (s);
}
