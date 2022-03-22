/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:10:21 by cnysten           #+#    #+#             */
/*   Updated: 2022/02/19 12:12:02 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	get_char_width(int c)
{
	if ((c & 0b11100000) == 0b11000000)
		return (2);
	else if ((c & 0b11110000) == 0b11100000)
		return (3);
	else if ((c & 0b11111000) == 0b11110000)
		return (4);
	return (0);
}

void	ft_putchar(char c)
{
	static char	arr[4];
	static int	char_width;
	static int	i;

	if (char_width == 0)
		char_width = get_char_width(c);
	if (char_width == 0)
		write(1, &c, 1);
	else if (i == char_width - 1)
	{
		arr[i++] = c;
		write(1, arr, char_width);
		i = 0;
		char_width = 0;
	}
	else if (i < char_width - 1)
		arr[i++] = c;
}
