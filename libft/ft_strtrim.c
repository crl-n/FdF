/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:48:01 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/13 20:55:02 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	trimmed_len(char const *s)
{
	size_t	len;
	size_t	count;

	len = 0;
	count = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	while (*s)
	{
		count = 0;
		while (*s && !(*s == ' ' || *s == '\t' || *s == '\n'))
		{
			len++;
			s++;
		}
		while (*s == ' ' || *s == '\t' || *s == '\n')
		{
			s++;
			len++;
			count++;
		}
	}
	return (len - count);
}

char	*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	size = trimmed_len(s) + 1;
	trim = (char *) malloc(size * sizeof (char));
	if (!trim)
		return (NULL);
	i = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	while (s[i] && i < size - 1)
	{
		trim[i] = s[i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
