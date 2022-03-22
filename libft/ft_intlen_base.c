/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:02:07 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/22 19:02:09 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen_base(int value, int base)
{
	size_t	len;

	len = 0;
	if (value == 0)
		return (1);
	if (base == 10 && value < 0)
	{
		value = -value;
		len++;
	}
	while (value > 0)
	{
		value = value / base;
		len++;
	}
	return (len);
}
