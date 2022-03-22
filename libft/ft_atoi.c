/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:31:14 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/13 20:43:52 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_iswhite(int c)
{
	if (c == ' ')
		return (1);
	if (c >= '\t' && c <= '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	nb;

	sign = 1;
	nb = 0;
	while (ft_iswhite(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += (unsigned int)(*str - '0');
		str++;
	}
	return ((int) nb * sign);
}
