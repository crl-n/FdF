/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:23:19 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/13 20:47:18 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strdel(char **as)
{
	if (!as)
		return ;
	if (*as)
		free(*as);
	*as = NULL;
}