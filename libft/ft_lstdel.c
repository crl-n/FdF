/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:47:53 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/26 15:08:16 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*next;

	if (!alst || !del)
		return ;
	node = *alst;
	while (node)
	{
		del(node->content, node->content_size);
		if (node->next)
			next = node->next;
		else
			next = NULL;
		free(node);
		node = next;
	}
	*alst = NULL;
}
