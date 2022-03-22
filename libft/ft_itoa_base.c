/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:11:36 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/13 15:53:03 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

/* get_char() converts an int into a corresponding digit of its base */

static char	get_char(int n)
{
	char	c;

	c = (char) n + '0';
	if (c > '9')
		c += 7;
	return (c);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	size_t	size;

	size = ft_intlen_base(value, base) + 1;
	str = (char *) malloc(size * sizeof (char));
	if (!str)
		return (NULL);
	str[--size] = '\0';
	while (value >= base)
	{
		str[--size] = get_char(value % base);
		value = value / base;
	}
	str[--size] = value + '0';
	return (str);
}
