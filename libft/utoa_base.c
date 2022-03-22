/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:30:59 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/22 19:02:52 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static char	get_uint_char(unsigned int n)
{
	char	c;

	c = (char) n + '0';
	if (c > '9')
	{
		c += 39;
	}
	return (c);
}

static size_t	ft_uint_len_base(unsigned int n, int base)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char	*utoa_base(unsigned int n, int base)
{
	char	*s;
	size_t	size;

	size = ft_uint_len_base(n, base) + 1;
	s = (char *) malloc(size * sizeof (char));
	if (!s)
		return (NULL);
	s[--size] = '\0';
	while (size > 0)
	{
		s[--size] = get_uint_char(n % base);
		n = n / base;
	}
	return (s);
}
