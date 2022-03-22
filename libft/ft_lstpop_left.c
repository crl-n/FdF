/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:38:40 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/13 20:59:54 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	*ft_lstpop_left(t_list **head)
{
	t_list	*lst;
	void	*content;

	if (!head)
		return (NULL);
	if (!*head)
		return (NULL);
	lst = *head;
	if (lst->next)
		*head = lst->next;
	else
		*head = NULL;
	lst->next = NULL;
	content = lst->content;
	free(lst);
	return (content);
}
