/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:15:51 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/22 19:00:09 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr2(int n)
{
	char	str[12];
	size_t	i;
	int		sign;

	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		ft_bzero(str, 12);
		i = 10;
		sign = 1;
		if (n < 0)
		{
			sign = -1;
			n = n * (-1);
		}
		while (n > 9)
		{
			str[i--] = (char)(n % 10 + '0');
			n = n / 10;
		}
		str[i] = (char)(n + '0');
		ft_putstr(str + i);
	}
}
